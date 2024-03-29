class Solution {
public:
    int evalRPN(vector<string>& A) {
        stack<int> s;
        for (auto &t : A) {
            if (isdigit(t.back())) {
                s.push(stoi(t));
            } else {
                int n = s.top();
                s.pop();
                switch (t[0]) {
                    case '+': s.top() += n; break;
                    case '-': s.top() -= n; break;
                    case '*': s.top() *= n; break;
                    case '/': s.top() /= n; break;
                }
            }
        }
        return s.top();
    }
};