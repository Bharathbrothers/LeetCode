class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()) + 1;

        while (l < r) {
            int m = (l + r) >> 1;
            int hour = 0;
            for (int pile : piles) hour += (pile - 1) / m + 1;
            if (hour <= H)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};