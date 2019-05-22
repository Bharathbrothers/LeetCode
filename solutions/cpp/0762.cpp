class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        // (10100010100010101100)2 = (665772)10
        constexpr int magic = 665772;
        int ans = 0;

        for (int n = L; n <= R; n++)
            if (magic & (1 << __builtin_popcountll(n))) ans++;

        return ans;
    }
};