#include <iostream>
using namespace std;

class Solution {
  public:
      long dp[100001];
      long getMaximumPoints(int size, vector<vector<int>> &questions, int idx) {
          // Base Case
          if(idx >= size)
              return 0;
  
          if(dp[idx] != -1)   
              return dp[idx];
  
          long include = questions[idx][0] + getMaximumPoints(size, questions, idx + questions[idx][1] + 1);
          long exclude = getMaximumPoints(size, questions, idx + 1);
  
          return dp[idx] = max(include, exclude);
      }
      long long mostPoints(vector<vector<int>>& questions) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = questions.size();
  
          memset(dp, -1, sizeof(dp));
          return getMaximumPoints(size, questions, 0);
      }
  };