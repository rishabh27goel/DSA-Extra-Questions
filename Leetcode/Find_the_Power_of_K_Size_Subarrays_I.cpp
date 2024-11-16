#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute Force
    vector<int> resultsArray(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        vector<int> power;
        for(int i = 0; i <= n - k; i++) {
            bool exists = true;
            int maxNum = nums[i];

            for(int j = 0; j < k-1; j++) {
                if(nums[i + j] + 1 != nums[i + j + 1]) {
                    exists = false;
                    break;
                }
                maxNum = max(nums[i + j + 1], maxNum);
            }   

            power.push_back(exists ? maxNum : -1);
        }

        return power;
    }
};