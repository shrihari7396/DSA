#include <bits/stdc++.h>
using namespace std;

void Printing_upto_n(int a, int b){
    if(a < b){
        return;
    }
    Printing_upto_n(a-1,b);
    cout << a << endl;
}
int main(void){
    int a,b;
    cin >> a >> b;
    Printing_upto_n(a,b);
    return 0;
}