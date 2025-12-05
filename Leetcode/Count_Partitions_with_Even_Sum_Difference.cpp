#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countPartitions(vector<int>& nums) {
          int size = nums.size();
  
          int totalSum = 0;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              totalSum += nums[currIdx];
          }
  
          int partitions = 0;
          int leftSum = 0;
          for(int currIdx = 0; currIdx < size - 1; currIdx++) {
              leftSum += nums[currIdx];
              int rightSum = totalSum - leftSum;
  
              if(abs(leftSum - rightSum) % 2 == 0) 
                  partitions++;
          }
          return partitions;
      }
  };