class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() < 1) return 1;

        for (int i = 0; i < nums.size(); i++)
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;

        return nums.size() + 1;
    }
};