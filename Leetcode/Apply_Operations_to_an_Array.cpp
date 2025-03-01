#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> applyOperations(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int numSize = nums.size();
  
          for(int idx = 0; idx < numSize - 1; idx++) {
              if(nums[idx] == nums[idx + 1]) {
                  nums[idx] += nums[idx];
                  nums[idx + 1] = 0;
              }
          }
  
          int nonZeroIdx = 0;
          int currIdx = 0;
  
          while(currIdx < numSize) {
              if(nums[currIdx] == 0) {
                  currIdx++;
              }
              else {
                  swap(nums[nonZeroIdx], nums[currIdx]);
                  nonZeroIdx++;
                  currIdx++;
              }
          }
  
          return nums;
      }
  };