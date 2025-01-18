#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<int>v= {1,2,3,4,5,5,6,7,8};
    int size = v.size();
    int low = 0;
    int high = size - 1;
    int target;
    cin >> target;
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(v[mid] > target) {
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
        cout << ans << endl;
    return 0;
}