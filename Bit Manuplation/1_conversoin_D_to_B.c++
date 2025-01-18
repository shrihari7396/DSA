#include <bits/stdc++.h>
using namespace std;

string D_to_B(int n) {
    string s ;
    
    // Edge case for 0
    if (n == 0) {
        return "0";
    }
    
    while (n != 0) {
        int x = n % 2;
        s.push_back(x + '0'); // Convert integer to character '0' or '1'
        n /= 2;
    }
    
    reverse(s.begin(), s.end()); // Reverse the string to get correct binary representation
    
    return s;
}

int main(void) {
    int N;
    cin >> N;
    string s = D_to_B(N);
    cout << s <<  endl;
    return 0;
}