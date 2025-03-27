#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minimumIndex(vector<int>& nums) {
          int size = nums.size();
  
          // Getting the dominant element
          int dominant = -1;
          int votes = 0;
  
          for(int idx = 0; idx < size; idx++) {
              if(votes == 0 || dominant == nums[idx]) {
                  dominant = nums[idx];
                  votes++;
              }
              else
                  votes--;
          }
  
          // Getting the count of dominant element
          int dominantCount = 0;
          for(int idx = 0; idx < size; idx++) {
              if(dominant == nums[idx])
                  dominantCount++;
          }
  
          // Finding a valid split
          int currCount = 0;
          for(int idx = 0; idx < size; idx++) {
              if(dominant == nums[idx])
                  currCount++;
  
              int leftSize = idx + 1;
              int rightSize = size - idx - 1;
              int remainingCount = dominantCount - currCount;
  
              if((leftSize / 2) < currCount && (rightSize / 2) < remainingCount)
                  return idx;
          }
  
          return -1;
      }
  };