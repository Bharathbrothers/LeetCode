class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size() - 1;

        while (l <= r) {
            int m = (l + r) >> 1;
            if (citations[m] == citations.size() - m)
                return citations[m];
            else if (citations[m] > citations.size() - m)
                r = m - 1;
            else
                l = m + 1;
        }

        return citations.size() - (r + 1);
    }
};