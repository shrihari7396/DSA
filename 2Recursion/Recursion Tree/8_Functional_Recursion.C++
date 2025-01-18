// Function Recursion.
#include <bits/stdc++.h>
using namespace std;

int summation(int i){
    if(i == 0){
        return 0;
    }
    return i + summation(i-1);
}

int main(void){
    int s;
    cin >> s;
    cout << summation(s) << endl;
    return 0;
}
