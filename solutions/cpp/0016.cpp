class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return sum;
                else if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }

        return ans;
    }
};