#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maximumLength(vector<int>& nums, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          vector<vector<int>> dp(k, vector<int> (k, 0));
          int maxLength = 0;
  
          for(int currNum : nums) {
              currNum %= k;
              for(int prev = 0; prev < k; prev++) {
                  dp[prev][currNum] = dp[currNum][prev] + 1;
                  maxLength = max(dp[prev][currNum], maxLength);
              }
          }
          return maxLength;
      }
  };