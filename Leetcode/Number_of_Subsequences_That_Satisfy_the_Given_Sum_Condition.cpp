#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int mod = 1e9 + 7;
      int getLowerBound(int size, vector<int> &nums, int startIdx, int target) {
          int leftIdx = startIdx;
          int rightIdx = size - 1;
  
          int bound = -1;
          while(leftIdx <= rightIdx) {
              int midIdx = leftIdx + (rightIdx - leftIdx) / 2;
              if(nums[midIdx] <= target) {
                  bound = midIdx;
                  leftIdx = midIdx + 1;
              }
              else {
                  rightIdx = midIdx - 1;
              }
          }
          return bound;
      }
  
      int numSubseq(vector<int>& nums, int target) {
          int size = nums.size();
  
          vector<long> power(size);
          int p = 1;
  
          for(int idx = 0; idx < size; idx++) {
              power[idx] = p;
              p = (p * 2L) % mod;
          }
  
          // Sort the array
          sort(nums.begin(), nums.end());
  
          long subSeqCount = 0;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(nums[currIdx] + nums[currIdx] <= target)     
                  subSeqCount++;
  
              int lowerBoundIdx = getLowerBound(size, nums, currIdx + 1, target - nums[currIdx]);
              if(lowerBoundIdx != -1) {
                  int count = lowerBoundIdx - currIdx;
                  long subCount = power[count] - 1;
                  subSeqCount = (subSeqCount + subCount) % mod;
              }
          }
          return subSeqCount;
      }
  };