#include <bits/stdc++.h>
using namespace std;

int fibonacci_number(int N){
    if(N == 0  || N == 1){
        return N;
    }
    return fibonacci_number(N - 1) + fibonacci_number(N - 2);
}

int main(void){
    int N;
    cin >> N;
    cout<< fibonacci_number(N) << endl;
    return 0;
}