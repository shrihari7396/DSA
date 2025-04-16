#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int minimumMultiplications(vector<int>& arr, int start, int end) {
          // code here
          vector<int> dist(100000, 1e9);
          queue<pair<int, int>> q;
          q.push({start, 0});
          dist[start] = 0;
          while(!q.empty()) {
              auto it = q.front();
              int node = it.first;
              int step = it.second;
              q.pop();
              for(int i=0;i<arr.size();i++) {
                  int next = arr[i]*node % 100000;
                  if(step+1 < dist[next]) {
                      q.push({next, step+1});
                      dist[next] = step+1;
                  }
              }
          }
          return dist[end] != 1e9 ? dist[end] : -1;
      }
  };
  
int main(int argc, char** argv) {

    return 0;
}