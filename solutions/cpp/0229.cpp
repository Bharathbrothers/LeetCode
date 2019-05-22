class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++) map[nums[i]]++;

        vector<int> ans;
        for (auto it = map.begin(); it != map.end(); it++)
            if (it->second > nums.size() / 3)
                ans.push_back(it->first);

        return ans;
    }
};