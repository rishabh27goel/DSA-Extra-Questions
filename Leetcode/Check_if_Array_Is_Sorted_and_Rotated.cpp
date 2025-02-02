#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int subs = 0;
        int j = 0;

        while(j < n) {
            int prev = nums[j];
            int idx = j + 1;
            while(idx < n && prev <= nums[idx]) {
                prev = nums[idx];
                idx++;
            }
            j = idx;
            subs++;
        }

        if(subs == 1)
            return true;

        else if(subs == 2) 
            return nums[0] >= nums[n-1];

        return false;
    }
};