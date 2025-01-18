#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string prefix_to_infix(string& s) {
        int size = s.size();
        stack<string> st;
        for(int i = size - 1; i >= 0; i--) {
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9') {
                st.push(string(1, s[i]));
            } else {
                if(st.size() >= 2) {
                    string s1 = st.top(); st.pop();
                    string s2 = st.top(); st.pop();
                    string add = '(' + s1 + s[i] + s2 + ')';
                    st.push(add);
                } else {
                    return "Invalid Input";
                }
            }
        }
        return "";
    }
};
