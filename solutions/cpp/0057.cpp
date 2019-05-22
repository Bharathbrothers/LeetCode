class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = intervals.begin();
        while (it != intervals.end() && (*it)[0] < newInterval[0]) it++;
        intervals.insert(it, newInterval);

        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            if (ans.empty() || interval[0] > ans.back()[1])
                ans.push_back(interval);
            else
                ans.back()[1] = max(ans.back()[1], interval[1]);
        }

        return ans;
    }
};