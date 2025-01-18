#include <bits/stdc++.h>
using namespace std;

vector<int> sort(vector<int>& a){
    int size = a.size();
    for(int i = 0; i < size - 1; i++){
            int count = 0;
        for(int j = i ; j < size; j++){
            if(a[j] < a[i]){
                swap(a[i],a[j]);
            count ++;
            }
        }
        if(count = 0){
            return a;
        }
    }
    return a;
}

vector<int> Slection_sort_in_desending_order(vector<int>& a){
    int n = a.size();
    for(int i = 0; i < n-1; i++){
        for(int j =  0; j < n; j++){
            if(a[j] > a[i]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
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
    vector<int>a = sort(v);
    for(auto it = a.begin(); it != a.end(); it++){
        cout << *(it) << " ";
    }
    return 0;
}
