class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyOne = INT_MAX;
        int buyTwo = INT_MAX;
        int sellOne = 0;
        int sellTwo = 0;

        for (const auto& price : prices) {
            buyOne = min(buyOne, price);
            sellOne = max(sellOne, price - buyOne);
            buyTwo = min(buyTwo, price - sellOne);
            sellTwo = max(sellTwo, price - buyTwo);
        }

        return sellTwo;
    }
};