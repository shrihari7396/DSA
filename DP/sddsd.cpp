#include <bits/stdc++.h> 
using namespace std;

bool helper(int i, int k, vector<int>& nums, int n, int iSum, map<pair<int, int>, bool>& dp) {
    if(i==n) {
        if(iSum == k) {
            return dp[{i, iSum}] = true;
            
        }
        return dp[{i, iSum}] = false;
    }

    iSum += nums[i];
    if(dp.find({i, iSum})!=dp.end()) {
        return dp[{i, iSum}];
    }

    if(helper(i+1, k, nums, n, iSum, dp)) {
        return dp[{i, iSum}] = true;
    }
    

    iSum -= nums[i];
    if(dp.find({i, iSum}) != dp.end()) {
        return dp[{i, iSum}] = true;;
    }

    if(helper(i+1, k, nums, n, iSum, dp)) {
        return dp[{i,iSum}] = true;
    }

    return dp[{i, iSum}] = false;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    map<pair<int,int>, bool> dp;
    int hash = 0;
    return helper(0, k, arr, n, hash, dp);
}

int main(int argc,char** argv) {

    return 0;
}