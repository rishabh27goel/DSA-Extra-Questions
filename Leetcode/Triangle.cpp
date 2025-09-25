#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // int dp[205][205];
      // int getMinTotal(int size, vector<vector<int>> &triangle, int rowIdx, int colIdx) {
      //     if(rowIdx >= size)
      //         return 0;
  
      //     if(dp[rowIdx][colIdx] != -1)
      //         return dp[rowIdx][colIdx];
  
  
      //     int callOne = triangle[rowIdx][colIdx] + getMinTotal(size, triangle, rowIdx + 1, colIdx);
  
      //     int callTwo = triangle[rowIdx][colIdx] + getMinTotal(size, triangle, rowIdx + 1, colIdx + 1);
  
      //     return dp[rowIdx][colIdx] = min(callOne, callTwo);
      // }
  
      // int minimumTotal(vector<vector<int>>& triangle) {
      //     int size = triangle.size();
  
      //     memset(dp, -1, sizeof(dp));
  
      //     return getMinTotal(size, triangle, 0, 0);
      // }
  
      int minimumTotal(vector<vector<int>>& triangle) {
          int size = triangle.size();
  
          int dp[205][205];
          memset(dp, 0, sizeof(dp));
  
          for(int rowIdx = size - 1; rowIdx >= 0; rowIdx--) {
              for(int colIdx = 0; colIdx < triangle[rowIdx].size(); colIdx++) {
                  int callOne = triangle[rowIdx][colIdx] + dp[rowIdx + 1][colIdx];
  
                  int callTwo = triangle[rowIdx][colIdx] + dp[rowIdx + 1][colIdx + 1];
  
                  dp[rowIdx][colIdx] = min(callOne, callTwo);
              }
          }
  
          return dp[0][0];
      }
  };