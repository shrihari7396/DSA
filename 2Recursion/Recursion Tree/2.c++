#include <bits/stdc++.h>
using namespace std;

void Print_name_n_times(int n){
    if (n == 0){
        return;
    }
    cout << "Shrihari" << endl;
    Print_name_n_times(n-1);
}

int main(void){
    int i;
    cout << "Enter how many time name will printed: " ;
    cin >> i;
    Print_name_n_times(i);
    return 0;
}