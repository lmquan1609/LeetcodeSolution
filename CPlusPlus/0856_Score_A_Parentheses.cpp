class Solution {
public:
    int scoreOfParentheses(string S) {
        int N = S.size();
        stack<int> s;
        for (int i = 0; i < N; i++) {
            if (S[i] == '(') {
                s.push(-1);
            } else {
                if (!s.empty() && s.top() == -1) {
                    s.pop();
                    s.push(1);
                } else {
                    int local = 0;
                    while (!s.empty() && s.top() != -1) {
                        local += s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(2 * local);
                }
            }
        }
        int result = 0;
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        return result;
    }
};
