#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int x, int y) {
    if ((a ^ 1) == b && x >= y) {
        cout << y << endl;
        return;
    } 
    if (a > b && (a^1) > b) {
        cout << -1 << endl;
        return;
    }

    int c = b - a;
    if(x <= y) {
        cout << c*x << endl;
        return;
    }
    
    // Cost if you use x repeatedly (step-by-step) vs using y as a direct shortcut
    // int ans = (c - 1) * x + y;
    // cout << ans << endl;
    int ans = 0;
    while(a != b) {
        if((a^1) > a)  {
            a = a ^ 1;
            ans += y;
        } else {
            a = a + 1;
            ans += x;
        }
    }
    cout << ans << endl;
    return ;
}

int main() {
    int t;
    cin >> t; // Read t once before loop
    string s;
    isalnum
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        solve(a, b, x, y);
    }
    return 0;
}
