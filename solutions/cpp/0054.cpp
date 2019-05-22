class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();

        vector<int> ans(m * n);
        int count = 0;
        int direction = 0;

        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        while (true) {
            if (up > down || right < left) return ans;

            if (direction == 0) {
                for (int i = left; i <= right; i++)
                    ans[count++] = matrix[up][i];
                up++;
            } else if (direction == 1) {
                for (int i = up; i <= down; i++)
                    ans[count++] = matrix[i][right];
                right--;
            } else if (direction == 2) {
                for (int i = right; i >= left; i--)
                    ans[count++] = matrix[down][i];
                down--;
            } else {
                for (int i = down; i >= up; i--)
                    ans[count++] = matrix[i][left];
                left++;
            }

            direction = (direction + 1) % 4;
        }

        return ans;
    }
};