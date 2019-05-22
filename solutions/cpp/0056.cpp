class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), compare);

        for (const auto& interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            else
                ans.back()[1] = max(ans.back()[1], interval[1]);
        }

        return ans;
    }

private:
    bool static compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};