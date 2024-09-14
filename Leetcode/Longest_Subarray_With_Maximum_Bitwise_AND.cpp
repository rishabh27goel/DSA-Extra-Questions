#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        int maxVal = 0;
        int maxLength = 0;
        int j = 0;

        while(j < n) {            
            int len = 0;
            int val = nums[j];

            while(j < n && val == nums[j]) {
                len++, j++;
            }

            if(maxVal < val) {
                maxLength = len;
                maxVal = val;
            }
            else if(maxVal == val) {
                maxLength = max(len, maxLength);
            }
        }

        return maxLength;
    }
};