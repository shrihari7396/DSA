#include <bits/stdc++.h>
using namespace std;

int main(void){

    int a ;
    cin >> a;
    while(a > 0){
        cout << a%10 << endl;
        a = a / 10;
    }
    return 0;
}