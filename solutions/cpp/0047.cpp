class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, nums.size(), used, path, ans);
        return ans;
    }

private:
    void dfs(vector<int>& nums, int target, vector<bool>& used, vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || i > 0 && used[i - 1] && nums[i] == nums[i - 1])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, target - 1, used, path, ans);
            path.pop_back();
            used[i] = false;
        }
    }
};