#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool isTrionic(vector<int>& nums) {
          int size = nums.size();
          if(size == 3)   return false;
          
          int currIdx = 0;
  
          int lastValue = nums[currIdx++];
          bool valid = false;
  
          while(currIdx < size && lastValue < nums[currIdx]) {
              lastValue = nums[currIdx];
              valid = true;
              currIdx++;
          }
          if(!valid)  return false;
  
          valid = false;
          while(currIdx < size && lastValue > nums[currIdx]) {
              lastValue = nums[currIdx];
              valid = true;
              currIdx++;
          }
          if(!valid)  return false;
  
          valid = false; 
          while(currIdx < size && lastValue < nums[currIdx]) {
              lastValue = nums[currIdx];
              valid = true;
              currIdx++;
          }
  
          if(!valid)  return false;
          return currIdx == size;
      }
  };