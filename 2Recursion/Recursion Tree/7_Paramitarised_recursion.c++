// Prameterised Recursion.
#include  <bits/stdc++.h>
using namespace std;
/*There are different ways to implement recursion, and two notable variations are parameterized recursion and functional recursion. */
int summation(int i, int sum){
    if(i == 0){
        return sum;
    }
    summation(i-1,sum + i);
}

int main(void){
    int i,j;
    cin >> i;
    j = 0;
    cout << summation(i,j) << endl;
    return 0;
}