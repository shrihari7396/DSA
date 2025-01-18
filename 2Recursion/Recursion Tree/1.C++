#include <bits/stdc++.h>
using namespace std;

void hello(int n){
    if(n == 0){
        return ;
    }
    cout << "Hello World !" << endl;
    hello(n - 1);
}
int main(void){
    // Calling of the funcrion by the itself is called the recursion.
    int i; cout << "Enter Number of times to write Hello World !" << endl;
    cin >> i ;
    hello(i);
    return 0;
}