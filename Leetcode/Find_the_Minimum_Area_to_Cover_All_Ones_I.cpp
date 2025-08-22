#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minimumArea(vector<vector<int>>& grid) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int rowSize = grid.size();
          int colSize = grid[0].size();
  
          int minH = colSize;
          int maxH = -1;
  
          int minV = rowSize;
          int maxV = -1;
  
          for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
              for(int colIdx = 0; colIdx < colSize; colIdx++) {
                  if(grid[rowIdx][colIdx] == 1) {
                      minH = min(colIdx, minH);
                      maxH = max(colIdx, maxH);
  
                      minV = min(rowIdx, minV);
                      maxV = max(rowIdx, maxV);
                  }
              }
          }
  
          if(maxH == -1 || maxV == -1)
              return 0;
  
          return (maxH - minH + 1) * (maxV - minV + 1);
      }
  };