#include <bits/stdc++.h>
using namespace std;

class Qu{
public:
    stack<int> st;
    stack<int> s_temp;

    void push(int x) {
        while(st.size()) {
            s_temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(s_temp.size()) {
            while(s_temp.size()) {
                st.push(s_temp.top());
                s_temp.pop();
            }
        }
    }

    int top() {
        return st.top();
    }

    int pop() {
        int temp = st.top();
        st.pop();
        return temp;
    }

    int top() {
        return st.top();
    }
};


// second approach

class Queue{
public:
    stack<int>s1;
    stack<int>s2;
    void push(int x) {
        s1.push(x);
    }

    int top() {
        if(s2.empty()) return -1;
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    int pop() {
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        int nums = s2.top(); 
        return nums;
    }

};