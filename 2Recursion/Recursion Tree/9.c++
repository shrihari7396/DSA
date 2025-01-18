#include <bits/stdc++.h>
using namespace std;

long factorial(long n){
    if (n == 1){
        return 1;
    }
    return n*factorial(n-1);
}

int main(void){
    long N;
    cout << "Enter Number whose factorial you want: " ;
    cin >> N;
    cout << "Factorial of "<< N << " is: " << factorial(N);
    return 0;
}