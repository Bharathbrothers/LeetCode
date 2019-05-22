class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); i++) map[list1[i]] = i;

        vector<string> ans;
        int min = INT_MAX;

        for (int i = 0; i < list2.size(); i++) {
            if (!map.count(list2[i])) continue;
            int sum = map[list2[i]] + i;
            if (sum < min) ans.clear();
            if (sum <= min) {
                min = sum;
                ans.push_back(list2[i]);
            }
        }

        return ans;
    }
};