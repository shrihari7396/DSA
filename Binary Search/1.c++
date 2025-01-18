#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int target ;
    cin >> target;
    vector<int> v(N);
    for(auto it : v){
        int tmp ;
        cin >> tmp;
        v.emplace_back(tmp);
    }  
    int low = 0;
    int high = N-1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(v[mid] == target) {
            cout << v[mid] << " Shrihari" << endl;
        }  else if(target > v[mid]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
         }
    return 0;
}