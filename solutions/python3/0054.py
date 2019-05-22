class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])

        ans = [0] * (m * n)
        count = 0
        direction = 0

        up = 0
        down = m - 1
        left = 0
        right = n - 1

        while True:
            if up > down or right < left:
                return ans

            if direction == 0:
                for i in range(left, right + 1):
                    ans[count] = matrix[up][i]
                    count += 1
                up += 1
            elif direction == 1:
                for i in range(up, down + 1):
                    ans[count] = matrix[i][right]
                    count += 1
                right -= 1
            elif direction == 2:
                for i in range(right, left - 1, -1):
                    ans[count] = matrix[down][i]
                    count += 1
                down -= 1
            else:
                for i in range(down, up - 1, -1):
                    ans[count] = matrix[i][left]
                    count += 1
                left += 1

            direction = (direction + 1) % 4

        return ans
