#include <bits/stdc++.h>
using namespace std;

bool Is_prime_1(int i){
    int count = 0;
    for (int j = 1; j <= i; j ++){
        if(i % j == 0){
            count ++;
        }
    }
    if(count == 2){
        return true;
    }else{
        return false;
    }
}

bool Is_prime_2(int a){
    int count  = 0;
    for(int i = 1; i <= sqrt(a); i++){
        if(a % i == 0){
            count ++;
            if(i != a/i){
                count ++;
            }
        }
    }
    if(count == 2){
        return true;
    }else{
        return false;
    }
}
int main(void){
    int s;
    cin >> s;
    cout << (Is_prime_1(s) ? "True" : "False") << endl;
    cout << (Is_prime_2(s) ? "True" : "False") << endl;
    return 0;
}