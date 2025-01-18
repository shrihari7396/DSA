#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin >> s;
    int size = s.size();

    int hash[256] = {0};
    for(int i = 0; i < size; i++){
        int ascii = s[i];
        hash[ascii] += 1;
    }

    int queries ;
    cin >> queries;

    while(queries > 0){
        char chracter;
        cin >> chracter;
        int ascii1 = chracter;
        cout << hash[ascii1]<<endl;
        queries --;
    }
   return 0;
}