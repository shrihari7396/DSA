#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        
        string x1 = x;  // Start with initial x
        int ans = 1;    // Count how many times x has been appended
        
        // Check if s is already a substring of x1
        if(x1.find(s) != string::npos) {
            cout << 0 << endl;
            continue;
        }
 
        // Continue concatenating x1 with x and checking
        while(x1.size() < m * n) {
            x1 += x1;
            ans++;
            if(x1.find(s) != string::npos) {
                cout << ans << endl;
                break;
            }
        }
        
        // If after all concatenations we cannot find s in x1
        if(x1.size() >= m * n && s.find(x1) == string::npos) {
            cout << -1 << endl;
        }
    }
    return 0;
}