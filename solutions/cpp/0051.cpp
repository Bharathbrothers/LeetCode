class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        dfs(0, cols, diag1, diag2, board, ans);
        return ans;
    }

private:
    void dfs(int y, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<string>& board, vector<vector<string>>& ans) {
        if (y == cols.size()) {
            ans.push_back(board);
            return;
        }

        for (int x = 0; x < cols.size(); x++) {
            if (!cols[x] && !diag1[x + y] && !diag2[x - y + cols.size() - 1]) {
                board[y][x] = 'Q';
                cols[x] = diag1[x + y] = diag2[x - y + cols.size() - 1] = true;
                dfs(y + 1, cols, diag1, diag2, board, ans);
                cols[x] = diag1[x + y] = diag2[x - y + cols.size() - 1] = false;
                board[y][x] = '.';
            }
        }
    }
};