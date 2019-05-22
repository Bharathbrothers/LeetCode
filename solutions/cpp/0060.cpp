class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> nums(n);
        vector<int> fact(n, 1);

        for (int i = 0; i < n; i++) nums[i] = i + 1;
        for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i;

        k--;

        for (int i = n; i >= 1; i--) {
            int j = k / fact[i - 1];
            k %= fact[i - 1];
            ans.append(to_string(nums[j]));
            nums.erase(nums.begin() + j);
        }

        return ans;
    }
};