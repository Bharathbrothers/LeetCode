class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(0, board);
    }

private:
    bool dfs(int s, vector<vector<char>>& board) {
        if (s == 81) return true;

        int i = s / 9;
        int j = s % 9;

        if (board[i][j] != '.') return dfs(s + 1, board);

        for (char c = '1'; c <= '9'; c++)
            if (isValid(i, j, c, board)) {
                board[i][j] = c;
                if (dfs(s + 1, board)) return true;
                board[i][j] = '.';
            }

        return false;
    }

    bool isValid(int row, int col, char c, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.' && board[i][col] == c) return false;
            if (board[row][i] != '.' && board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};