#include <bits/stdc++.h>
using namespace std;

class Solution {
    int priority(char ch) {
        if (ch == '+' || ch == '-') {
            return 1;
        } else if (ch == '*' || ch == '/') {
            return 2;
        } else if (ch == '^') {
            return 3;
        } else {
            return -1; // For parentheses and other non-operators
        }
    }

public:
    string infixToPrefix(string s) {
        stack<char> st;     // Stack for operators
        string ans = "";    // Result string for prefix

        // Step 1: Reverse the string and adjust parentheses
        reverse(s.begin(), s.end());
        for (char &ch : s) {
            if (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
        }

        // Step 2: Process the reversed infix expression
        for (char ch : s) {
            if (isalnum(ch)) {
                // Operand: Add directly to the result
                ans += ch;
            } else if (ch == '(') {
                // Open parenthesis: Push to stack
                st.push(ch);
            } else if (ch == ')') {
                // Close parenthesis: Pop until '(' is found
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Pop the '('
            } else {
                // Operator: Process based on precedence
                while (!st.empty() && priority(st.top()) >= priority(ch) &&
                        !(ch == '^' && st.top() == '^')) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Step 3: Pop remaining operators in the stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Step 4: Reverse the result to get the final prefix expression
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string infix = "(A+B)*(C-D)";
    string prefix = sol.infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}
