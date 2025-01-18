#include <bits/stdc++.h>
using namespace std;

class Solution_1 {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// longest prefix match approach

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i + 1] > nums[i]) {
                index = i;
                break;
            }
            i--;
        }

        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 1; i > index; i--) {
            if (nums[index] < nums[i]) {
                swap(nums[index], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }

};