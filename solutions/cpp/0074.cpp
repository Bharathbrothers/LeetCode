class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;

        int l = 0;
        int r = matrix.size() * matrix[0].size();

        while (l < r) {
            int m = (l + r) >> 1;
            int i = m / matrix[0].size();
            int j = m % matrix[0].size();
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target)
                r = m;
            else
                l = m + 1;
        }

        return false;
    }
};