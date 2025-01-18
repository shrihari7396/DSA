#include <bits/stdc++.h>
using namespace std;
int Recursive_binary(vector<int>& v, int low, int high,int target) {
    if(low > high) {
        return -1;
    }
    int mid = (low + high)/2;
    if(v[mid] == target) {
        return mid;
    }else if (v[mid] < target){
        return Recursive_binary(v, mid+1,high,target);
    }else{
        return Recursive_binary(v,low,mid-1,target);
    }
}
int main(void) {
    int N;
    cout << "Enter size of array: " ;
    cin >>N;
    vector<int> v(N,0);
    for(int i = 0; i < 10; i++){
        int tmp ;
        cin >> tmp;
        v[i] = tmp;
    }
    int target;
    cout << "Enter target: " ;
    cin >> target;
    cout << Recursive_binary(v,0,v.size()-1,target);
    
    return 0;
}