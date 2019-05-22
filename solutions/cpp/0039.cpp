class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path, ans);
        return ans;
    }

private:
    void dfs(vector<int>& candidates, int target, int s, vector<int>& path, vector<vector<int>>& ans) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = s; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
    }
};