class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int net = 0;
        int sum = 0;

        for (int i = 0; i < gas.size(); i++) {
            net += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                ans = i + 1;
            }
        }

        return net < 0 ? -1 : ans;
    }
};