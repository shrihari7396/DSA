#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char ch) {
        if(ch == '+' || ch == '-') {
            return 1;
        } 
        else if(ch == '*' || ch == '/') {
            return 2;
        } 
        else if(ch == '^') {
            return 3;
        } 
        else return -1;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        stack<int> st;
        int size = s.size();        
        string ans = "";
        for(int i = 0; i < size; i++) {
            char ch = s[i];
            if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
                ans += s[i];
            } else if(ch == '(') {
                st.push(s[i]);
            } else if(ch == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while(!st.empty() && priority(ch) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()) {
            char ch = st.top();
            ans += ch;
            st.pop();
        }
        return ans;
    }
};


int main(int argc, char**argv) {

    return 0;
}