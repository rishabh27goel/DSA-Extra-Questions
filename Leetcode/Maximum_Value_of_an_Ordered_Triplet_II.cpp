#include <iostream>
using namespace std;

class Solution {
  public:
      long long maximumTripletValue(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
  
          int size = nums.size();
  
          long maxNum = 0;
          long maxDiff = 0;
          long maxValue = 0;
  
          for(int idx = 0; idx < size; idx++) {
              maxValue = max(maxValue, maxDiff * nums[idx]);
              maxDiff = max(maxDiff, maxNum - nums[idx]);
              maxNum = max(maxNum, 1L * nums[idx]);
          }
  
          return maxValue;
      }
  };