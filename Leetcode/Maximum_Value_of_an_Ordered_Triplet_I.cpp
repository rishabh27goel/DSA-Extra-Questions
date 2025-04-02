#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // long long maximumTripletValue(vector<int>& nums) {
      //     ios_base::sync_with_stdio(false);
      //     // cin.tie(NULL);
      //     // cout.tie(NULL);
  
      //     int size = nums.size();
  
      //     long maxValue = 0;
      //     for(int outerIdx = 0; outerIdx < size; outerIdx++) {
      //         for(int middleIdx = outerIdx + 1; middleIdx < size; middleIdx++) {
      //             for(int innerIdx = middleIdx + 1; innerIdx < size; innerIdx++) {
      //                 maxValue = max(maxValue, (nums[outerIdx] - nums[middleIdx]) * 1L * nums[innerIdx]);
      //             }
      //         }
      //     }
      //     return maxValue;
      // }
  
      // If we make the nums[k] as fixed then we have to maximize on (nums[i] - nums[j])
      // For each nums[j] we can track previous nums[i]
      long long maximumTripletValue(vector<int>& nums) {
          int size = nums.size();
  
          long maxNum = 0;
          long maxDiff = 0;
          long maxValue = 0;
  
          for(int idx = 0; idx < size; idx++) {
              maxValue = max(maxValue, maxDiff * nums[idx]);
              maxDiff = max(maxDiff, maxNum - nums[idx]);
              maxNum = max(maxNum, 1L * nums[idx]);
          }
  
          return maxValue;
      }
  };