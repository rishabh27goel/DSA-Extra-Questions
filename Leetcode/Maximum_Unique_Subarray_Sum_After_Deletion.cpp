#include <iostream>
using namespace std;

class Solution {
  public:
      int maxSum(vector<int>& nums) {
          int size = nums.size();
  
          int maxNum = INT_MIN;
          for(int idx = 0; idx < size; idx++) {
              maxNum = max(maxNum, nums[idx]);
          }
  
          // If only negative numbers are there
          if(maxNum < 0)  return maxNum;
  
          int totalSum = 0;
          bool exists[101] = {0};
  
          for(int idx = 0; idx < size; idx++) {
              if(nums[idx] < 0)
                  continue;
  
              if(!exists[nums[idx]])
                  totalSum += nums[idx];
  
              exists[nums[idx]] = true;
          }
          
          return totalSum;
      }
  };