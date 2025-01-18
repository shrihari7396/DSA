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
    for(int i = 1; i <= limit; i++) {
        if(Is_possible(v, i,k)) {
            result = i ;
        }else {
            break;
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