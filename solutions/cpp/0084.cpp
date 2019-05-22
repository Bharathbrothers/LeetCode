class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> stack;
        stack.push(-1);

        for (int i = 0; i <= heights.size(); i++) {
            while (stack.top() != -1 && (i == heights.size() || heights[i] < heights[stack.top()])) {
                int h = heights[stack.top()];
                stack.pop();
                ans = max(ans, h * (i - stack.top() - 1));
            }
            stack.push(i);
        }

        return ans;
    }
};