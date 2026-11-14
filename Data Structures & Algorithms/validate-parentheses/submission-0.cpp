class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char key : s) {
            if (key == '(' || key == '{' || key == '[') stk.push(key);
            else {
                if (stk.empty()) return false;
                char t = stk.top();
                if ((key == ')' && t != '(') ||
                    (key == '}' && t != '{') ||
                    (key == ']' && t != '[')) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};