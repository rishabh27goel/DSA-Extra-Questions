#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int longestSubarray(vector<int>& nums) {
          int size = nums.size();
  
          int maxNum = 0;
          int maxLength = 0;
          int currIdx = 0;
          
          while(currIdx < size) {
              int currNum = nums[currIdx];
              int count = 0;
              while(currIdx < size && currNum == nums[currIdx]) {
                  count++, currIdx++;
              }
  
              if(maxNum < currNum) {
                  maxNum = currNum;
                  maxLength = count;
              }
              else if(maxNum == currNum) {
                  maxLength = max(maxLength, count);
              }
          }   
          return maxLength;
      }
  };