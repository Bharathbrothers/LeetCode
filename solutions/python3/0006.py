class Solution:
    def convert(self, s: str, numRows: int) -> str:
        rows = [''] * numRows
        direction = (numRows == 1) - 1
        k = 0

        for c in s:
            rows[k] += c
            if k == 0 or k == numRows - 1:
                direction *= -1
            k += direction

        return ''.join(rows)
