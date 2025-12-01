#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minSubarray(vector<int>& nums, int p) {
          int size = nums.size();
  
          int runningSum = 0;
          for(int currIdx = 0; currIdx < size; currIdx++)
              runningSum = (runningSum + nums[currIdx]) % p;
  
          if(runningSum == 0)   return 0;
  
  
          unordered_map<int, int> modMap;
          int minSize = size + 1;
          int target = runningSum;
          runningSum = 0;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              runningSum = (runningSum + nums[currIdx]) % p;
  
              if(runningSum == target) minSize = min(minSize, currIdx + 1);
  
              int modValue = (runningSum - target + p) % p;
              if(modMap.find(modValue) != modMap.end()) 
                  minSize = min(minSize, currIdx - modMap[modValue]);
          
              modMap[runningSum] = currIdx;
          }
  
          // We are not allowed to remove the whole array
          return minSize >= size ? -1 : minSize;
      }
  };