#include <iostream>
#include <vectoe>
using namespace std;

class Solution {
  public:
      int findFinalValue(vector<int>& nums, int original) {
          int size = nums.size();
  
          bool exists[1001] = {0};
          for(int num : nums) {
              exists[num] = 1;
          }
  
          int currNum = original;
          while(currNum <= 1000 && exists[currNum]) {
              currNum *= 2;
          }
          return currNum;
      }
  };