class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool isAllNine = true;

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                isAllNine = false;
                break;
            } else {
                digits[i] = 0;
            }
        }

        if (isAllNine) digits.insert(digits.begin(), 1);

        return digits;
    }
};