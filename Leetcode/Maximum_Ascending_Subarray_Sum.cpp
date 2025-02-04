#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = 0;
        int j = 0;

        while(j < n) {
            int start = j + 1;
            int prevNum = nums[j];
            int total = nums[j];

            while(start < n && prevNum < nums[start]) {
                total += nums[start];
                prevNum = nums[start];
                start++;
            }

            maxSum = max(maxSum, total);
            j = start;
        }

        return maxSum;
    }
};