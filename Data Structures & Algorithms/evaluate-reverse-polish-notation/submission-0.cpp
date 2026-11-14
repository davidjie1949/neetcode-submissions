class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if (s == "+") stk.push(a+b);
                else if (s == "-") stk.push(a-b);
                else if (s == "*") stk.push(a*b);
                else stk.push(a / b);
            } else {
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};
