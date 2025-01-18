#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector  <int> v {2,3,45,67,677,5546};
    int n = v.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    int target ;
    cin >> target;
    while(low <= high) {
        int mid = (low + high)/2;
        if(v[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return 0;
}
