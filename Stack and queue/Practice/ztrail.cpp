#include <bits/stdc++.h>
using namespace std;

struct priorityq{
    int a[1000];
    int front;
    int rear;
};

class implementation{
    priorityq q;
    void init() {
        q.front = -1;
        q.rear = -1;
    }

    void insert(int item) {
        int j = q.rear;
        if(q.front==-1) {
            ++q.front;
            q.a[q.front]=item;
        } else {
            while(j >= 0 && q.a[j] > item) {
                q.a[j+1] = q.a[j];
                j--;
            }
            q.a[j+1] = item;
        }
        q.rear++;
    }

    int remove() {
        int item = q.a[q.front];
        q.front++;
        return item;
    }
};

int main(int argc, char** argv) {
    vector<int> an = {1232,23,131231,3,123134,12,3123,234234234,23234};
    sort(an.begin(), an.end());
    return 0;
}