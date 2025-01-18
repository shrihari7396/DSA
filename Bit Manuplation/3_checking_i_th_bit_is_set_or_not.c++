#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int sift_it_by;
    cin >> sift_it_by;

    // Check if the bit at position sift_it_by is set
    if ((n & (1 << sift_it_by)) != 0) {
        cout << "set" << endl;
    } else {
        cout << "Not Set" << endl;
    }

    return 0;
    
}
s