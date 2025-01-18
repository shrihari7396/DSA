#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int hash[130] = {0};
    for(int i = 0; i < N; i++){
        hash[arr[i]] += 1; 
    }

    int Q;
    cin >> Q;
    while(Q > 0){
        int Number;
        cin >> Number;
        cout << (hash[Number]);
        Q--;
    }

    return 0;
}