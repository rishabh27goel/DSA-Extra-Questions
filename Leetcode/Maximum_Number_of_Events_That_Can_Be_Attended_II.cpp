#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int getUpperBound(int size, vector<vector<int>> &events, int startIdx, int target) {
          int leftIdx = startIdx;
          int rightIdx = size - 1;
  
          int upperIdx = -1;
          while(leftIdx <= rightIdx) {
              int middleIdx = leftIdx + (rightIdx - leftIdx) / 2;
              if(events[middleIdx][0] > target) {
                  upperIdx = middleIdx;
                  rightIdx = middleIdx - 1;
              }
              else {
                  leftIdx = middleIdx + 1;
              }
          }
          return upperIdx;
      }
  
      int findMaximumSum(int size, vector<vector<int>> &events, int currIdx, int currK, vector<vector<int>> &dp) {
          // Base Case
          if(currK == 0) 
              return 0;
  
          if(currIdx == size)
              return INT_MIN;
  
          if(dp[currIdx][currK] != -1)
              return dp[currIdx][currK];
  
  
          int upperBoundIdx = getUpperBound(size, events, currIdx + 1, events[currIdx][1]);
    
          int includeCall = events[currIdx][2];
          if(upperBoundIdx != -1) {
              includeCall = max(includeCall, includeCall + findMaximumSum(size, events, upperBoundIdx, currK - 1, dp));
          }
  
          int excludeCall = findMaximumSum(size, events, currIdx + 1, currK, dp);
  
          return dp[currIdx][currK] = max(includeCall, excludeCall);
      }
  
      int maxValue(vector<vector<int>>& events, int k) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          cout.tie(NULL);
  
          int size = events.size();
  
          // Sort the array
          sort(events.begin(), events.end(), [&](vector<int> &v1, vector<int> &v2) {
              if(v1[0] == v2[0])
                  return v1[1] < v2[1]; 
  
              return v1[0] < v2[0];
          });
  
          vector<vector<int>> dp(size + 1, vector<int> (k + 1, -1));
  
          return findMaximumSum(size, events, 0, k, dp);
      }
  };