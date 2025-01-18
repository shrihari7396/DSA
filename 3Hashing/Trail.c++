#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int a[N] = {0};
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    map <int,int>hash;
    for(int i = 0; i < N; i++){
        hash[a[i]] += 1;
    }
    int q;
    cin >> q;
    while (q > 0)
    {
        int Numbers;
        cin >> Numbers;
        cout << hash[Numbers] << endl;
        q--;
    }
    

    return 0;
}