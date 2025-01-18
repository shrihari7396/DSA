#include <bits/stdc++.h>
using namespace std;

vector<int> insertion_sort(vector<int> a){
    int size = a.size();
    for(int i = 0; i < size; i++){
        int j = i;
        while(j > 0 && a[j - 1] > a[j]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
    return a;
}
int main(void){
    vector<int>v;
    int N,temp;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp ;
        v.emplace_back(temp);
    }
    vector<int>a = insertion_sort(v);
    for(auto it = a.begin(); it != a.end(); it++){
        cout << *(it) << " ";
    }
    return 0;
}
