#include <bits/stdc++.h>
using namespace std;

int GCD(int s,int h){
    int GCD = 0;
    int min = 0;
    if(s>h){
        min = h;
    }else{
        min = s;
    }
    for(int i = 1; i <= min; i++){
        if (s % i == 0 && h % i == 0){
            GCD = i;
        }
    }
    return GCD;
}

int main(void){
    int i,j;
    cin >> i >> j;
    cout << GCD(i,j);
    return 0;
}


long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
}