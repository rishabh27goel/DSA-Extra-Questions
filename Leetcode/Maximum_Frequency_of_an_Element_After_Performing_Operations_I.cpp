#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maxFrequency(vector<int>& nums, int k, int numOperations) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
      
          int freqMap[200005] = {0};
          int pointMap[300005] = {0};
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              freqMap[nums[currIdx] + 100000]++;
              pointMap[nums[currIdx] - k + 100000]++;
              pointMap[nums[currIdx] + k + 1 + 100000]--;
          }
  
          int maxFreq = 0;
          int freqCount = 0;
  
          for(int idx = 0; idx <= 200000; idx++) {
              freqCount += pointMap[idx];
              
              int totalCount = freqCount;
              int originalCount = freqMap[idx];
  
              maxFreq = max(maxFreq, originalCount + min(totalCount - originalCount, numOperations));
  
          }
          return maxFreq;
      }
  };