#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<bool> prefixesDivBy5(vector<int>& nums) {
          int size = nums.size();
  
          int prefix = 0;
          vector<bool> result;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              prefix = ((prefix * 2) + nums[currIdx]) % 5;
              result.push_back(prefix == 0);
          }
          return result;
      }
  };