class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        nSum(nums, target, 4, path, ans);
        return ans;
    }

private:
    void nSum(vector<int>& nums, int target, int n, vector<int>& path, vector<vector<int>>& ans) {
        if (nums.size() < n || n < 2 || target < nums[0] * n || target > nums.back() * n)
            return;

        if (n == 2) {
            int l = 0;
            int r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    vector<int> vec(path);
                    vec.insert(vec.end(), {nums[l], nums[r]});
                    ans.push_back(vec);
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                } else if (nums[l] + nums[r] < target) {
                    l++;
                } else {
                    r--;
                }
            }
        } else {
            for (int i = 0; i < nums.size() - n + 1; i++) {
                if (i == 0 || i > 0 && nums[i - 1] != nums[i]) {
                    vector<int>::const_iterator first = nums.begin() + i + 1;
                    vector<int>::const_iterator last = nums.end();
                    vector<int> newNums(first, last);
                    path.push_back(nums[i]);
                    nSum(newNums, target - nums[i], n - 1, path, ans);
                    path.pop_back();
                }
            }
        }
    }
};