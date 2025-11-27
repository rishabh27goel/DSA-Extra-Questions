#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int dp[50001][51];
      int mod = 1e9 + 7;
  
      int getPathsNumber(int rowSize, int colSize, vector<vector<int>>& grid, int rowIdx, int colIdx, int remain, int k) {
          if(rowIdx >= rowSize || colIdx >= colSize)
              return 0;
  
          if(rowIdx == rowSize - 1 && colIdx == colSize - 1)
              return (remain + grid[rowIdx][colIdx]) % k == 0;
  
          if(dp[rowIdx * colSize + colIdx][remain] != -1)
              return dp[rowIdx * colSize + colIdx][remain];
  
          long rightCall = getPathsNumber(rowSize, colSize, grid, rowIdx, colIdx + 1, (remain + grid[rowIdx][colIdx]) % k, k);
  
          long downCall = getPathsNumber(rowSize, colSize, grid, rowIdx + 1, colIdx, (remain + grid[rowIdx][colIdx]) % k, k);
  
          return dp[rowIdx * colSize + colIdx][remain] = (rightCall + downCall) % mod;
      }
  
      int numberOfPaths(vector<vector<int>>& grid, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int rowSize = grid.size();
          int colSize = grid[0].size();
  
          memset(dp, -1, sizeof(dp));
  
          return getPathsNumber(rowSize, colSize, grid, 0, 0, 0, k);
      }
  };