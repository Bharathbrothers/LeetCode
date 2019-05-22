class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = goal; i >= 0; i--)
            if (i + nums[i] >= goal)
                goal = i;

        return !goal;
    }
};