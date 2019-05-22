class Solution {
public:
    string getHint(string secans, string guess) {
        int A = 0;
        int B = 0;
        map<char, int> map1;
        map<char, int> map2;

        for (int i = 0; i < secans.length(); i++) {
            if (secans[i] == guess[i])
                A++;
            else {
                map1[secans[i]]++;
                map2[guess[i]]++;
            }
        }

        for (int i = 0; i <= 9; i++)
            B += min(map1['0' + i], map2['0' + i]);

        return to_string(A) + "A" + to_string(B) + "B";
    }
};