class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool isFirstRow = false;
        bool isFirstCol = false;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
                isFirstRow = true;

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                isFirstCol = true;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (isFirstRow)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        if (isFirstCol)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};