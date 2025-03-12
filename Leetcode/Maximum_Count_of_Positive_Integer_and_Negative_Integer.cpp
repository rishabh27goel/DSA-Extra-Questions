#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maximumCount(vector<int>& nums) {
          int size = nums.size();
  
          int negativeCount = 0;
          int positiveCount = 0;
          int currIdx = 0;
  
          while(currIdx < size && nums[currIdx] < 0) {
              negativeCount++;
              currIdx++;
          }
          while(currIdx < size && nums[currIdx] == 0) {
              currIdx++;
          }
          while(currIdx < size && nums[currIdx] > 0) {
              positiveCount++;
              currIdx++;
          }
  
          return max(positiveCount, negativeCount);
      }
  };