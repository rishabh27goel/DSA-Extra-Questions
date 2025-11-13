#include <iostream>
#include <vector>
using namespace stdl;

class Solution {
  public:
      int minOperations(vector<int>& nums) {
          int size = nums.size();
  
          int gcdNum = 0;
          int onesCount = 0;
  
          for(int num : nums) {
              if(num == 1)  onesCount++;
              gcdNum = gcd(gcdNum, num);
          }
  
          if(onesCount > 0)   return size - onesCount;
          if(gcdNum > 1)      return -1;
  
          // Because the elements are adjacent so, we have check for subarray combination to get 1
          int minLength = size;
          for(int outerIdx = 0; outerIdx < size; outerIdx++) {
              int currGcd = 0;
              for(int innerIdx = outerIdx; innerIdx < size; innerIdx++) {
                  currGcd = gcd(currGcd, nums[innerIdx]);
                  if(currGcd == 1) {
                      minLength = min(minLength, innerIdx - outerIdx + 1);
                      break;
                  }
              }    
          }
  
          // Here (minLength - 1) operations are needed to get the single element to 1
          // Now we can make rest (size - 1) elements to 1
          return (minLength - 1) + (size - 1);
      }
  };