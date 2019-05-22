class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        bool isNegative = false;
        int j = 0;

        while (j < str.size() && str[j] == ' ') j++;
        if (j == str.size()) return 0;
        if (str[j] == '-') {
            isNegative = true;
            j++;
        } else if (str[j] == '+') {
            j++;
        }

        for (int i = j; i < str.size(); i++) {
            if (str[i] < '0' || str[i] > '9')
                break;
            else {
                ans = ans * 10 + (str[i] - '0');
                if (isNegative && -ans <= INT_MIN) return INT_MIN;
                if (!isNegative && ans >= INT_MAX) return INT_MAX;
            }
        }

        return isNegative ? -ans : ans;
    }
};