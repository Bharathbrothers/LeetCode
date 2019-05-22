class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board:
            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(board, word, i, j, 0):
                    return True

        return False

    def dfs(self, board: List[List[str]], word: str, i: int, j: int, pos: int) -> bool:
        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]) or board[i][j] != word[pos] or board[i][j] == '*':
            return False
        if pos == len(word) - 1:
            return True

        c = board[i][j]
        board[i][j] = '*'

        flag = \
            self.dfs(board, word, i + 1, j, pos + 1) or \
            self.dfs(board, word, i - 1, j, pos + 1) or \
            self.dfs(board, word, i, j + 1, pos + 1) or \
            self.dfs(board, word, i, j - 1, pos + 1)

        board[i][j] = c

        return flag
