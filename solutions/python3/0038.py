class Solution:
    def countAndSay(self, n: int) -> str:
        map = {1: '1', 2: '11', 3: '21', 4: '1211', 5: '111221'}
        if n <= 5:
            return map[n]

        for i in range(6, n + 1):
            s = ''
            j = 0
            while j <= len(map[i - 1]) - 2:
                count = 1
                while j <= len(map[i - 1]) - 2 and map[i - 1][j] == map[i - 1][j + 1]:
                    count += 1
                    j += 1
                s += str(count) + map[i - 1][j]
                j += 1
            if j == len(map[i - 1]) - 1:
                s += str(1) + map[i - 1][j]
            map[i] = s

        return map[n]
