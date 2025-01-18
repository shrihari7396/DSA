#include <bits/stdc++.h>
using namespace std;

void Print_numbers_upto_n(int a, int b){
    if(a > b){
        return;
    }
    cout << a << endl;
    Print_numbers_upto_n(a+1,b);
}

int main(void){
    int a ,b;
    cin >> a >> b;
    Print_numbers_upto_n(a,b);
    return 0;
}