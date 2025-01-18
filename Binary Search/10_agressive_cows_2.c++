#include <bits/stdc++.h>
using namespace std;

bool Is_possible(vector<int>& cows, int d , int k) {
    int size = cows.size();
    int last = cows[0];
    int cntcows = 1;
    for(int i = 1; i < size; i++) {
        if(cows[i]-last >= d) {
            last = cows[i];
            cntcows++;
        if(cntcows >= k) {
            return true;
        }
        }
    }
    return false;
}

int aggressiveCows(vector <int>& v, int k ) {
    int size = v.size();
    int result  = 0;
    sort(v.begin(), v.end());
    int limit = v.back() - v.front();
    int low = 0;
    int high = size - 1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(Is_possible(v,mid,k)) {
            low = mid + 1;
            result = mid;
        }else{
            high = mid - 1;
        }
    }
    return result;
}

int main(void) {
     vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    // return 0;
    return 0;
}