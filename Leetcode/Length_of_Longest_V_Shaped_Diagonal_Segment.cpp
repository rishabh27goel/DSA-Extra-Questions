#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int dp[501][501][4][2];
      int xPos[4] = {-1, -1, 1, 1};
      int yPos[4] = {-1, 1, 1, -1};
  
      int getVShapedDiagonal(int rowSize, int colSize, vector<vector<int>>& grid, int rowIdx, int colIdx, int direction, bool turn, int target) {
          int currX = rowIdx + xPos[direction];
          int currY = colIdx + yPos[direction];
      
          if(currX < 0 || currY < 0 || currX >= rowSize || currY >= colSize)
              return 0;
  
          if(grid[currX][currY] != target)
              return 0;
  
          if(dp[currX][currY][direction][turn] != -1)
              return dp[currX][currY][direction][turn];
  
          // Now we are at new position
          int sameDirection = 1 + getVShapedDiagonal(rowSize, colSize, grid, currX, currY, direction, turn, 2 - target);
  
          int turnDirection = 0;
          if(turn) {
              turnDirection = 1 + getVShapedDiagonal(rowSize, colSize, grid, currX, currY, (direction + 1) % 4, turn - 1, 2 - target);
          }
          else {
              turnDirection = 1 + getVShapedDiagonal(rowSize, colSize, grid, currX, currY, direction, turn, 2 - target);
          }
          return dp[currX][currY][direction][turn] = max(sameDirection, turnDirection);
      }
  
      int lenOfVDiagonal(vector<vector<int>>& grid) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int rowSize = grid.size();
          int colSize = grid[0].size();
  
          // Set the default values to -1
          memset(dp, -1, sizeof(dp));
  
          int maxLength = 0;
          for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
              for(int colIdx = 0; colIdx < colSize; colIdx++) {
                  if(grid[rowIdx][colIdx] == 1) {     // Staring point is 1 
                      for(int direction = 0; direction < 4; direction++) {
                          int currLength = 1 + getVShapedDiagonal(rowSize, colSize, grid, rowIdx, colIdx, direction, 1, 2);
                          maxLength = max(maxLength, currLength);
                      }
                  }
              }
          }
          return maxLength;
      }
  };