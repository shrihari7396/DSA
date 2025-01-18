#include <bits/stdc++.h>
using namespace std;
int element_in_pascal_trangle(int n, int r) {
        int res = 1;
    for(int i = 0; i < r; i++) {
        res = res*(n-i);
        res = res/(i + 1);
    }
    return res;
}

vector<int> row_in_the_pascal_triangle(int n){
    vector<int>nums;
    // for(int i =0; i <= n; i++){
    //     int tmp = element_in_pascal_trangle(n,i);
    //     nums.emplace_back(tmp);
    // }
    int res = 1;
    for(int i = 0; i < n; i++) {
        res = res*(n-i);
        res = res/(i + 1);
    }
    return nums;
}

vector<vector<int>> Hole_pascal_triangle(int n){
    vector<vector<int>> nums;
    for(int i = 0; i < n; i++){
        vector<int> temp = row_in_the_pascal_triangle(i);
        nums.emplace_back(temp);
    }
    return nums;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> v = Hole_pascal_triangle(n);
    for (const auto& row : v) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}