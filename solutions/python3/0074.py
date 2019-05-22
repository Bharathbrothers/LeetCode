class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False

        l = 0
        r = len(matrix) * len(matrix[0])

        while l < r:
            m = (l + r) >> 1
            i = m // len(matrix[0])
            j = m % len(matrix[0])
            if matrix[i][j] == target:
                return True
            if matrix[i][j] > target:
                r = m
            else:
                l = m + 1

        return False
