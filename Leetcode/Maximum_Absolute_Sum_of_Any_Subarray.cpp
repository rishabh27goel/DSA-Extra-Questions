#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maxAbsoluteSum(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int numSize = nums.size();
  
          int maxSubarraySum = INT_MIN;
          int maxCurrentSum = 0;
  
          int minSubarraySum = INT_MAX;
          int minCurrentSum = 0;
  
          for(int idx = 0; idx < numSize; idx++) {
              maxCurrentSum += nums[idx];
              maxSubarraySum = max(maxSubarraySum, maxCurrentSum);
              maxCurrentSum = max(0, maxCurrentSum);
  
              minCurrentSum += nums[idx];
              minSubarraySum = min(minSubarraySum, minCurrentSum);
              minCurrentSum = min(0, minCurrentSum);
          }
  
          return max(abs(minSubarraySum), abs(maxSubarraySum));
      }
  };