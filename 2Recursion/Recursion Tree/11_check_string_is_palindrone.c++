#include <bits/stdc++.h>
using namespace std;

bool Is_palindrone(int i,int N, string s){
    if(i >= N/2){
        return true;
    }
    if(s[i] != s[N - i -1]){
        return false;
    }
    return Is_palindrone(i+1,N,s);
}

int main(void){
    string s;
    cin >> s;
    int i , N;
    N = s.size();
    i = 0;
    bool a = Is_palindrone(i,N,s);
    if(a){
        cout << "It is Palindrone" << endl;
    }else{
        cout << "It is not Palindrone" << endl;
    }
    return 0;
}