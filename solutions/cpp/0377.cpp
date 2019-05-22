class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> m(target + 1, -1);
        m[0] = 1;
        return dp(nums, target, m);
    }

private:
    int dp(vector<int>& nums, int target, vector<int>& m) {
        if (target < 0) return 0;
        if (m[target] != -1) return m[target];

        int ans = 0;
        for (const int num : nums) ans += dp(nums, target - num, m);

        return m[target] = ans;
    }
};