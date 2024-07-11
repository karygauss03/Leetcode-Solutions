class Solution {
public:
    string reverseParentheses(string s) {
       stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == ')') {
                string rev = "";
                while (!stack.empty() && stack.top() != '(') {
                    rev += stack.top();
                    stack.pop();
                }
                if (!stack.empty()) {
                    stack.pop(); // pop the opening bracket
                }
                for (int j = 0; j < rev.length(); j++) {
                    stack.push(rev[j]);
                }
            } else {
                stack.push(c);
            }
        }

        string result = "";
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result; 
    }
};