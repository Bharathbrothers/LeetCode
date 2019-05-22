class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []

        for i in range(1, numRows + 1):
            ans.append([1] * i)

        for i in range(2, numRows):
            for j in range(1, len(ans[i]) - 1):
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]

        return ans
