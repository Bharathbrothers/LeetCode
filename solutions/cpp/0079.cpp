class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, word, i, j, 0))
                    return true;

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int pos) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[pos] || board[i][j] == '*')
            return false;
        if (pos == word.length() - 1) return true;

        char c = board[i][j];
        board[i][j] = '*';

        bool flag = dfs(board, word, i + 1, j, pos + 1) ||
                    dfs(board, word, i - 1, j, pos + 1) ||
                    dfs(board, word, i, j + 1, pos + 1) ||
                    dfs(board, word, i, j - 1, pos + 1);

        board[i][j] = c;

        return flag;
    }
};