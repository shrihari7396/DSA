#include <bits/stdc++.h>
using namespace std;

int B_to_D(string& S){
    int n = S.size();
    reverse(S.begin(), S.end());
    int pow_2 = 1;
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
       if(S[i] == '1') {
        ans += pow_2;
       }
    pow_2 = pow_2 * 2;
    }
    return ans;
}

int main(void) {
    string S;
    cin >> S;
    int ans = B_to_D(S);
    cout << ans << endl;
    return 0;
}