#include <iostream>
#include <vectoe>
using namespace std;

class Solution {
  public:
      bool kLengthApart(vector<int>& nums, int k) {
          int size = nums.size();
  
          int lastOne = -1;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(nums[currIdx] == 1) {
                  if(lastOne != -1) {
                      int diff = (currIdx - lastOne - 1);
                      if(diff < k)    return false;
                  }
                  lastOne = currIdx;
              }
          }
          return true;
      }
  };