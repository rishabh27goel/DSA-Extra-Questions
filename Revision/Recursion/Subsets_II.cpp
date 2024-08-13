#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void findSubsets(int n, vector<int> &nums, int idx, vector<int> &sub) {
        if(idx >= n) {
            result.push_back(sub);
            return;
        }

        sub.push_back(nums[idx]);
        findSubsets(n, nums, idx + 1, sub);
        sub.pop_back();

        int next = idx;
        while(next < n && nums[next] == nums[idx]){
            next++;
        }
        findSubsets(n, nums, next, sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> sub;
        findSubsets(n, nums, 0, sub);
        return result;
    }
};