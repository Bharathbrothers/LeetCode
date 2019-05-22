class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> set(nums.begin(), nums.end());

        for (auto& num : set)
            if (!set.count(num - 1)) {
                int currNum = num;
                int currAns = 1;
                while (set.count(currNum + 1)) {
                    currNum++;
                    currAns++;
                }
                ans = max(ans, currAns);
            }

        return ans;
    }
};