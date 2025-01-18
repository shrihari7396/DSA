#include <bits/stdc++.h>
using namespace std;

class St {
public:
    queue<int> q;
    void push(int x) {
        q.push(x);
        int size = q.size();
        for(int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int top() {
        return q.front();
    }

    void pop() {
        int ans  = q.front();
        q.pop();
    }

    int size() {
        return q.size();
    }
};