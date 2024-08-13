#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void findPermute(int n, vector<int> nums, int start){
        if(start == n-1){
            result.push_back(nums);
            return;
        }

        unordered_set<int> seen;
        for(int j = start; j < n; j++){
            // We want to run our recursion for only one time 
            if(seen.count(nums[j]))
                continue;

            seen.insert(nums[j]);
            swap(nums[j], nums[start]);
            findPermute(n, nums, start + 1);   
            swap(nums[start], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        findPermute(n, nums, 0);
        return result;
    }
};