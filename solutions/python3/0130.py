class Solution:
    def solve(self, board: List[List[str]]) -> None:
        if not board:
            return

        m = len(board)
        n = len(board[0])

        for i in range(m):
            self.dfs(board, i, 0)
            self.dfs(board, i, n - 1)

        for j in range(1, n - 1):
            self.dfs(board, 0, j)
            self.dfs(board, m - 1, j)

        for i in range(m):
            for j in range(n):
                board[i][j] = 'O' if board[i][j] == '.' else 'X'

    def dfs(self, board: List[List[str]], i: int, j: int) -> None:
        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]) or board[i][j] != 'O':
            return

        board[i][j] = '.'

        self.dfs(board, i, j + 1)
        self.dfs(board, i, j - 1)
        self.dfs(board, i + 1, j)
        self.dfs(board, i - 1, j)
