#include <bits/stdc++.h>
using namespace std;

bool Is_Armstrong_number(int s){
    int a = s;
    int b = s;
    int armstrong_number = 0;
    int n=0;
    while (b > 0){
        n ++;
        b = b/10;
    }
    
    while(a > 0){
        int temp = a%10;
        armstrong_number += pow(temp,n);
        a = a/10;
    }
    if(armstrong_number == s){
        return true;
    }else{
        return false;
    }
}

int main(void){
    int shrihari;
    cin >> shrihari ;
    cout << (Is_Armstrong_number(shrihari)? "True" : "False");
    return 0;
}