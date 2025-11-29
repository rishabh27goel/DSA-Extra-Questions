#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minOperations(vector<int>& nums, int k) {
          int size = nums.size();
  
          int totalSum = 0;
          for(int currIdx = 0; currIdx < size; currIdx++) 
              totalSum += nums[currIdx];
          
          return totalSum % k;
      }
  };