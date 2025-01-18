#include <bits/stdc++.h>
using namespace std;

void divisor(int a){
    vector<int>b;
    for (int i = 1; i*i <= a; i++){
        if(a % i == 0){
            b.emplace_back(i);
            if(a/i != i ){
                b.emplace_back(a/i);
            }
        }
    }
    sort(b.begin(),b.end());
    for(auto it = b.begin();it != b.end(); it++){
        cout << *(it) << " ";
    }
}
int main(void){
    int i;
    cin >> i;
    divisor(i);
    return 0;
}