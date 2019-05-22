class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = find(nums, target, true);
        if (leftIndex == nums.size() || nums[leftIndex] != target)
            return {-1, -1};

        return {leftIndex, find(nums, target, false) - 1};
    }

private:
    int find(vector<int>& nums, int target, bool isLeft) {
        int l = 0;
        int r = nums.size();

        while (l < r) {
            int m = (l + r) >> 1;
            if (target < nums[m] || (isLeft && target == nums[m]))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};