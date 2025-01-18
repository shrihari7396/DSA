// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//     string bS(int N) {
//         if(N == 0) return "0";
//         string ans = "";
//         while(N > 0) {
//             ans += N%2 == 0 ? '0' : '1';
//             N = N >> 1;
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }

//     int sB(const string& S) {
//     int n = S.size();
//     reverse(S.begin(), S.end());
//     int pow_2 = 1;
//     int ans = 0;
//     for(int i = n-1; i >= 0; i--) {
//        if(S[i] == '1') {
//         ans += pow_2;
//        }
//     pow_2 = pow_2 * 2;
//     }
//     return ans;
//     }

// public:
//     int maxGoodNumber(vector<int>& nums) {
//         int N = nums.size();
//         string ans = "";
//         int maxN = INT_MIN;
//         while(next_permutation(nums.begin(), nums.end())) {
//             string temp = "";
//             for(int i = 0; i < nums.size(); i++) {
//                 temp +=  bS(nums[i]);
//             }
//             maxN = max(maxN, sB(temp));
//         }
//         return maxN;
//     }
// };

#include <iostream>
using namespace std;

int main()
{
    cerr << "Enter file" ;
    return 0;
}