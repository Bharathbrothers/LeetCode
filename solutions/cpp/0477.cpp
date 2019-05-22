class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int mask = 1;

        for (int i = 0; i < 30; i++) {
            int onesCount = 0;
            for (const int num : nums)
                if (num & mask) onesCount++;
            ans += (nums.size() - onesCount) * onesCount;
            mask = mask << 1;
        }

        return ans;
    }
};