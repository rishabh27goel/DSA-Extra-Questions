#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maximumDifference(vector<int>& nums) {
          int size = nums.size();
  
          int prevMinNum = INT_MAX;
          int maxDiff = -1;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(nums[currIdx] - prevMinNum > 0)
                  maxDiff = max(maxDiff, nums[currIdx] - prevMinNum);
  
              prevMinNum = min(prevMinNum, nums[currIdx]);
          }
  
          return maxDiff;
      }
  };