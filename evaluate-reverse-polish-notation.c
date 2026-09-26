class Solution {
public:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const string& token : tokens) {
            if (!isOperator(token)) {
                s.push(stoi(token));
            } else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                if (token == "+") s.push(a + b);
                else if (token == "-") s.push(a - b);
                else if (token == "*") s.push(a * b);
                else if (token == "/") s.push(a / b); // Integer division
            }
        }

        return s.top();
    }
};