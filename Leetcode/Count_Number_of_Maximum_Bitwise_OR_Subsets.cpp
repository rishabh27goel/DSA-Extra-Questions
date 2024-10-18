#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int countMaxOrSubsets(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();
    //     int power = pow(2, n);

    //     int maxOr = 0;
    //     for(int j = 0; j < n; j++) 
    //         maxOr |= nums[j];
        
    //     int subsets = 0;
    //     for(int p = 1; p < power; p++) {
    //         int currOr = 0;

    //         for(int j = 0; j < n; j++) {
    //             if(p & (1 << j))
    //                 currOr |= nums[j];
    //         }

    //         if(currOr == maxOr)
    //             subsets++;
    //     }   

    //     return subsets;
    // }

    // int findSubsets(int n, vector<int> &nums, int idx, int curr, int target, vector<vector<int>> &dp) {
    //     if(idx == n)
    //         return curr == target;

    //     if(dp[idx][curr] != -1)
    //         return dp[idx][curr]; 
            
    //     int newVal = (curr | nums[idx]);
    //     int include = findSubsets(n, nums, idx + 1, newVal, target, dp);
    //     int exclude = findSubsets(n, nums, idx + 1, curr, target, dp);

    //     return dp[idx][curr] = include + exclude;
    // }

    // int countMaxOrSubsets(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();
    //     int power = pow(2, n);

    //     int maxOr = 0;
    //     for(int j = 0; j < n; j++) 
    //         maxOr |= nums[j]; 

    //     vector<vector<int>> dp(n, vector<int> (maxOr + 1, -1));
    //     return findSubsets(n, nums, 0, 0, maxOr, dp);
    // }

    int findSubsets(int n, vector<int> &nums, int idx, int curr, int target) {
        if(idx == n)
            return curr == target;
            
        int newVal = (curr | nums[idx]);
        int include = findSubsets(n, nums, idx + 1, newVal, target);
        int exclude = findSubsets(n, nums, idx + 1, curr, target);

        return include + exclude;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();
        int power = pow(2, n);

        int maxOr = 0;
        for(int j = 0; j < n; j++) 
            maxOr |= nums[j]; 

        return findSubsets(n, nums, 0, 0, maxOr);
    }
};