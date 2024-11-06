#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findBits(int num) {
        int total = 0;
        while(num > 0) {
            if(num & 1)   total++;
            num >>= 1;
        }
        return total;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        int j = 0;
        int prevMax = -1;

        while(j < n) {
            int currBits = findBits(nums[j]);
            int currMin = INT_MAX;
            int currMax = INT_MIN;

            while(j < n && findBits(nums[j]) == currBits) {
                currMin = min(currMin, nums[j]);
                currMax = max(currMax, nums[j]);
                j++;
            }

            if(prevMax > currMin)
                return false;

            prevMax = currMax;
        }

        return true;
    }
};