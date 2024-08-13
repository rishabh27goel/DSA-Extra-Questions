#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // vector<vector<int>> result;
    // void findSubsets(int n, vector<int> &nums, int idx, vector<int> &sub){
    //     if(idx >= n){
    //         result.push_back(sub);
    //         return;
    //     }

    //     findSubsets(n, nums, idx + 1, sub);

    //     sub.push_back(nums[idx]);
    //     findSubsets(n, nums, idx + 1, sub);
    //     sub.pop_back();
    // }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> sub;
    //     findSubsets(n, nums, 0, sub);

    //     return result;
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<vector<int>> result;
        int p = pow(2, n);
        for(int j = 0; j < p; j++){

            vector<int> sub;
            for(int k = 0; k < n; k++){
                if(j & (1 << k)){
                    sub.push_back(nums[k]);
                }
            }
            result.push_back(sub);
        }

        return result;
    }
};