#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findSubsets(int n, int k, vector<int> &nums, int idx, vector<int> &dp){

        // Base Case
        if(idx == n)
            return 0;

        int include = 0;

        if(binary_search(dp.begin(), dp.end(), nums[idx] - k) == 0){
            dp.push_back(nums[idx]);
            include = 1 + findSubsets(n, k, nums, idx+1, dp);
            dp.pop_back();
        }

        int exclude = findSubsets(n, k, nums, idx+1, dp);

        return include + exclude;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());
        
        vector<int> dp;
        return findSubsets(n, k, nums, 0, dp);
    }
};