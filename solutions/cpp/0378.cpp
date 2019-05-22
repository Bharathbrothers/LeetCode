class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int r = matrix.back().back();

        while (l < r) {
            int m = (l + r) >> 1;
            int count = 0;
            for (auto& row : matrix)
                count += upper_bound(row.begin(), row.end(), m) - row.begin();
            if (count >= k)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};