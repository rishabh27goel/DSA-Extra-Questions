#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maximumUniqueSubarray(vector<int>& nums) {
          int size = nums.size();
  
          int maxUniqueSum = 0;
          int windowSum = 0;
  
          bool uniqueSt[10001];
          memset(uniqueSt, false, sizeof(uniqueSt));
  
          int startIdx = 0;
          int currIdx = 0;
  
          while(currIdx < size) {
              windowSum += nums[currIdx];
              while(startIdx <= currIdx && uniqueSt[nums[currIdx]]) {
                  uniqueSt[nums[startIdx]] = false;
                  windowSum -= nums[startIdx];
                  startIdx++;
              }
              
              uniqueSt[nums[currIdx]] = true;
              maxUniqueSum = max(maxUniqueSum, windowSum);
              currIdx++;
          }
  
          return maxUniqueSum;
      }
  };