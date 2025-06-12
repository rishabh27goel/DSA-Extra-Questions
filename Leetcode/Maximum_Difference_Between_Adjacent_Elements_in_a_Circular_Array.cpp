#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maxAdjacentDistance(vector<int>& nums) {
          int size = nums.size();
  
          int lastNum = nums[size - 1];
          int maxAbsValue = INT_MIN;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              maxAbsValue = max(maxAbsValue, abs(lastNum - nums[currIdx]));
              lastNum = nums[currIdx];
          }
          
          return maxAbsValue;
      }
  };