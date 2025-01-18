#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string postfixToInfix(string& s) {
        stack<string> st;
        int size = s.size();
        for(int i = 0; i < size; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
                st.push(string(1, s[i]));
            } else {
                if(st.size() >= 2) {
                    string s1 = st.top(); st.pop();
                    string s2 = st.top(); st.pop();
                    string add = '(' + s2 + s[i] + s1 + ')';
                    st.push(add);
                } else {
                    return "! INVALID" ;
                }
            }
        }
        return st.top();
    }
};

int main(void) {

    return 0;
}