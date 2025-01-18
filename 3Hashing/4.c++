#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    map<int ,int>m;
    for(int i = 0; i < N; i++){
        m[arr[i]] ++;
     }

    int Q;
    cin >> Q;
    while (Q > 0){
        int Number;
        cin >> Number ;
        cout << m[Number] << endl;
        Q--;
    }
    return 0;
}