class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int max = ans;
        int min = ans;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(max, min);
            max = std::max(nums[i], max * nums[i]);
            min = std::min(nums[i], min * nums[i]);
            ans = std::max(ans, max);
        }

        return ans;
    }
};