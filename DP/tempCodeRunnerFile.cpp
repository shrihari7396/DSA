#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int cnt = 0;
        int i = 0;

        while (i + k <= n) { // ensure we have k days remaining
            bool possible = true;
            for (int j = 0; j < k; j++) {
                if (a[i + j] == 1) { // rainy day
                    possible = false;
                    break;
                }
            }
            if (possible) {
                cnt++;
                i += k + 1; // skip k hike days + 1 break day
            } else {
                i++; // move to next day
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
