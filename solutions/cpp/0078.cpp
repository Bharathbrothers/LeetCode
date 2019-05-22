class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums, nums.size(), 0, path, ans);
        return ans;
    }

private:
    void dfs(vector<int>& nums, int target, int s, vector<int>& path, vector<vector<int>>& ans) {
        if (target < 0) return;

        ans.push_back(path);

        for (int i = s; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, target - 1, i + 1, path, ans);
            path.pop_back();
        }
    }
};