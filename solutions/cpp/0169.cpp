class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> map;
        const int n = nums.size();

        for (const int num : nums)
            if (++map[num] > n / 2)
                return num;

        return -1;
    }
};