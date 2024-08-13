#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void findPermute(int n, vector<int> &nums, int start){
        if(start == n-1){
            result.push_back(nums);
            return;
        }
            
        for(int j = start; j < n; j++){
            swap(nums[j], nums[start]);
            findPermute(n, nums, start + 1);
            swap(nums[start], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = nums.size();

        findPermute(n, nums, 0);
        return result;
    }
};