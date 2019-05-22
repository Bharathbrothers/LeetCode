class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int l = 0;
        int r = n - 1;
        vector<int> ans(n);

        while (n) {
            if (abs(A[l]) > abs(A[r]))
                ans[--n] = pow(A[l++], 2);
            else
                ans[--n] = pow(A[r--], 2);
        }

        return ans;
    }
};