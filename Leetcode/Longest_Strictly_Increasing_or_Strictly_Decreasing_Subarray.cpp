#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int longest = 0;
        int j = 0;

        while(j < n) {
            int prev = nums[j];
            int count = 1;
            int idx = j + 1;

            while(idx < n && prev < nums[idx]) {
                prev = nums[idx];
                count++, idx++;
            }

            longest = max(longest, count);
            j = idx;
        }

        j = 0;

        while(j < n) {
            int prev = nums[j];
            int count = 1;
            int idx = j + 1;

            while(idx < n && prev > nums[idx]) {
                prev = nums[idx];
                count++, idx++;
            }

            longest = max(longest, count);
            j = idx;
        }

        return longest;
    }
};