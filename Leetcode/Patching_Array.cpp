#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity : O(log(range) + (size))
    int minPatches(vector<int>& nums, int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        long size = nums.size();

        int totalPatches = 0;
        long maxReach = 0;
        int i = 0;

        // Till the time we have not reached the n as sum
        while(maxReach < (long) n){
            if(i < size && maxReach + 1 >= (long) nums[i]){
                maxReach += nums[i];
                i++;
            }
            else {
                // Adding maxReach + 1 as a patch
                maxReach += (maxReach + 1);
                totalPatches++;
            }
        }

        return totalPatches;
    }
};