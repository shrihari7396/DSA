#include <bits/stdc++.h>
using namespace std;

bool Ispalindrome(string i){
    int s =i.size();
    for(int j = 0; j <= s/2; j++){
        if(i[j] != i[s - j -1]){
            return false;
        }
    }
    return true;
}
int main(void){
    string a;
    cin >> a;
    cout <<  (Ispalindrome(a) ? "true" : "false");
    return 0;
}