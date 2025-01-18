#include <bits/stdc++.h>
using namespace std;

vector<int> Bubble_sorting(vector<int>& a){
    int n = a.size();
    int did_swap = 0;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(a[j] > a[j + 1]){
              swap(a[j],a[j+1]);
            }
        }
    if(did_swap == 0){
        return a;
    }
    }
    return a;
}
int main(void){    vector<int>v;
    int N,temp;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp ;
        v.emplace_back(temp);
    }
    vector<int>a = Bubble_sorting(v);
    for(auto it = a.begin(); it != a.end(); it++){
        cout << *(it) << " ";
    }
    return 0;
}