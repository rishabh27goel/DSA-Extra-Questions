#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // bool checkParition(int size, vector<int> &nums, int idx, int setSumOne, int setSumTwo) {
      //     if(idx == size)
      //         return setSumOne == setSumTwo;
  
      //     bool setOneCall = checkParition(size, nums, idx + 1, setSumOne + nums[idx], setSumTwo);
      //     bool setTwoCall = checkParition(size, nums, idx + 1, setSumOne, setSumTwo + nums[idx]);
  
      //     return setOneCall || setTwoCall;
      // }
  
      // bool canPartition(vector<int>& nums) {
      //     int size = nums.size();
  
      //     return checkParition(size, nums, 0, 0, 0);
      // }
  
      // int dp[201][20001];
      // bool checkParition(int size, vector<int> &nums, int idx, int setSum) {
      //     if(idx == size)
      //         return setSum == 0;
  
      //     if(setSum < 0)  
      //         return false;
  
      //     if(dp[idx][setSum] != -1)
      //         return dp[idx][setSum];
  
      //     bool includeCall = checkParition(size, nums, idx + 1, setSum - nums[idx]);
      //     bool excludeCall = checkParition(size, nums, idx + 1, setSum);
  
      //     return dp[idx][setSum] = (includeCall || excludeCall);
      // }
      // bool canPartition(vector<int>& nums) {
      //     ios_base::sync_with_stdio(false);
      //     // cin.tie(NULL);
      //     // cout.tie(NULL);
  
      //     int size = nums.size();
  
      //     int totalSum = 0;
      //     for(int currIdx = 0; currIdx < size; currIdx++) 
      //         totalSum += nums[currIdx];        
  
      //     // If the sum is odd the partition is not possible
      //     if(totalSum & 1)    return false;
  
      //     memset(dp, -1, sizeof(dp));
      //     return checkParition(size, nums, 0, totalSum / 2);
      // }
  
      // bool canPartition(vector<int>& nums) {
      //     ios_base::sync_with_stdio(false);
      //     // cin.tie(NULL);
      //     // cout.tie(NULL);
  
      //     int size = nums.size();
  
      //     int totalSum = 0;
      //     for(int currIdx = 0; currIdx < size; currIdx++) 
      //         totalSum += nums[currIdx];        
  
      //     // If the sum is odd the partition is not possible
      //     if(totalSum & 1)    return false;
  
      //     int dp[201][20001];
      //     memset(dp, false, sizeof(dp));
  
      //     int halfSum = totalSum / 2;
      //     for(int idx = size; idx >= 0; idx--) {
      //         for(int setSum = 0; setSum <= halfSum; setSum++) {
      //             if(idx == size) {
      //                 dp[idx][setSum] = (setSum == 0);
      //             }
      //             else {
      //                 bool includeCall = false;
      //                 if(setSum - nums[idx] >= 0)
      //                     includeCall = dp[idx + 1][setSum - nums[idx]];
  
      //                 bool excludeCall = dp[idx + 1][setSum];
  
      //                 dp[idx][setSum] = (includeCall || excludeCall);
      //             }                
      //         }
      //     }
      //     return dp[0][halfSum];
      // }
  
      bool canPartition(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          int totalSum = 0;
          for(int currIdx = 0; currIdx < size; currIdx++) 
              totalSum += nums[currIdx];        
  
          // If the sum is odd the partition is not possible
          if(totalSum & 1)    return false;
  
          int halfSum = totalSum / 2;
          vector<bool> prev(halfSum + 1, false);
          vector<bool> curr(halfSum + 1, false);
  
          for(int idx = size; idx >= 0; idx--) {
              for(int setSum = 0; setSum <= halfSum; setSum++) {
                  if(idx == size) {
                      curr[setSum] = (setSum == 0);
                  }
                  else {
                      bool includeCall = false;
                      if(setSum - nums[idx] >= 0)
                          includeCall = prev[setSum - nums[idx]];
  
                      bool excludeCall = prev[setSum];
  
                      curr[setSum] = (includeCall || excludeCall);
                  }                
              }
              prev = curr;
          }
          return prev[halfSum];
      }
  };