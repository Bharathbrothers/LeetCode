class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (const char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.empty() ||
                    (c == ')' && stack.top() != '(') ||
                    (c == '}' && stack.top() != '{') ||
                    (c == ']' && stack.top() != '['))
                    return false;
                stack.pop();
            }
        }

        return stack.empty();
    }
};