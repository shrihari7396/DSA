#include <bits/stdc++.h>
using namespace std;

void Printing_upto_n_in_reverse_order(int a, int b){
    if(a > b){
        return ;
    }
    Printing_upto_n_in_reverse_order(a+1,b);
    cout << a << endl;
}
int main(void){
    int a,b;
    a = 1;
    cin >> b;
    Printing_upto_n_in_reverse_order(a,b);
    return 0;
}