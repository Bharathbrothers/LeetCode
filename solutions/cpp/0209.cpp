class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= s) {
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};