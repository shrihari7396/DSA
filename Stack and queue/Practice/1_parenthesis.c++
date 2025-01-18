#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool checkParethesis(string &s) {
        int size = s.size();
        stack<char> st;
        for(int i = 0; i < size; i++) {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                if(s[i] == ')' && st.top() != '(' || s[i] == ']' && st.top() != '[' || s[i] == '}' && st.top() != '{') {
                    if(st.empty()) return false;
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(void) {

    return 0;
}