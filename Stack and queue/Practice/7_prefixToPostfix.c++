#include <bits/stdc++.h>
using namespace  std;

string prefixToPostfix(string& s) {
    int size = s.size();
    stack<string> st;
    for(int i = size - 1; i >= 0; i--) {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
            st.push(string(1, s[i]));
        } else {
            if(st.size() >= 2) {
                string s1 = st.top(); st.pop();
                string s2 = st.top(); st.pop();
                string ans = s2  + s1 + s[i];
                st.push(ans);
            }
        }
    }
    return st.top();
}

int main(void) {
    string s = "*-A/BC-/AKL";
    cout << prefixToPostfix(s) << endl;
    return 0;
}