#include <bits/stdc++.h>
using namespace std;

// first approach
int trap(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];

  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }

  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  
  return waterTrapped;
}


// Second approach
class Solution {
public:
    int trap(vector<int>& arr) {
        int lMax = 0;
        int rMax = 0;
        int l  = 0;
        int total = 0;
        int r = arr.size()-1;
        while(l < r) {
            if(arr[l] < arr[r]) {
                if(lMax >= arr[l]) {
                    total += lMax - arr[l];
                } else {
                    lMax = arr[l];
                }
                l++;
            } else {
                if(rMax >= arr[r]) {
                    total += rMax - arr[r];
                } else {
                    rMax = arr[r];
                }
                r--;
            }
        }
        return total;
    }
};