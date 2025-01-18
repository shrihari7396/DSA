#include <bits/stdc++.h>
using namespace std;

void Printing_number_upto_n_in_reverse_direction(int a, int b){
    if (a > b){
        return ;
    }
    cout << b << endl;
    Printing_number_upto_n_in_reverse_direction(a,b-1);
}

int main (void){
    int a,b;
    a = 1;
    cin >> b;
    Printing_number_upto_n_in_reverse_direction(a,b);
    return 0;
}
