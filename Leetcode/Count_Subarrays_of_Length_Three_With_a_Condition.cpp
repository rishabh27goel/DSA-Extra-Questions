#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countSubarrays(vector<int>& nums) {
          int size = nums.size();
  
          int subCount = 0;
          int currIdx = 2;
  
          while(currIdx < size) {
              int numOne = nums[currIdx - 2];
              int numTwo = nums[currIdx - 1];
              int numThree = nums[currIdx];
  
              if(2 * (numOne + numThree) == numTwo)   subCount++;
              currIdx++;
          }
  
          return subCount;
      }
  };