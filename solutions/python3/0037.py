class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        self.dfs(0, board)

    def dfs(self, s: int, board: List[List[str]]) -> bool:
        if s == 81:
            return True

        i = s // 9
        j = s % 9

        if board[i][j] != '.':
            return self.dfs(s + 1, board)

        for c in range(1, 10):
            if self.isValid(i, j, str(c), board):
                board[i][j] = str(c)
                if self.dfs(s + 1, board):
                    return True
                board[i][j] = '.'

        return False

    def isValid(self, row: int, col: int, c: str, board: List[List[str]]) -> bool:
        for i in range(9):
            if board[i][col] != '.' and board[i][col] == c:
                return False
            if board[row][i] != '.' and board[row][i] == c:
                return False
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] != '.' and \
                    board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
                return False
        return True
