class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size();

        while (l < r) {
            int m = (l + r) >> 1;
            if (letters[m] <= target)
                l = m + 1;
            else
                r = m;
        }

        return letters[l % letters.size()];
    }
};