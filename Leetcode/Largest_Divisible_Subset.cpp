#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // We will store the maximum subset leading to a specific element
      vector<int> largestDivisibleSubset(vector<int>& nums) {
          int size = nums.size();
  
          // Sort the array
          sort(nums.begin(), nums.end());
  
          // Using dynamic programming try to find the maximum subset 
          // while keeping track of the previousIdx
          vector<int> previousIdx(size, -1);
          vector<int> subsetCount(size, 1);
  
          int maxSubset = 1;
          int lastIdx = 0;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              for(int prevIdx = 0; prevIdx < currIdx; prevIdx++) {
                  if(nums[currIdx] % nums[prevIdx] == 0) {
                      if(subsetCount[prevIdx] + 1 > subsetCount[currIdx]) {
                          subsetCount[currIdx] = subsetCount[prevIdx] + 1;
                          previousIdx[currIdx] = prevIdx;
                      }
                  }
                  if(maxSubset < subsetCount[currIdx]) {
                      maxSubset = subsetCount[currIdx];
                      lastIdx = currIdx;
                  }
              }
          }
  
          // Creating the actual subset using the previousIdx
          vector<int> subset;
          int startIdx = lastIdx;
  
          while(startIdx != -1) {
              subset.push_back(nums[startIdx]);
              startIdx = previousIdx[startIdx];
          }
  
          return subset;
      }
  };