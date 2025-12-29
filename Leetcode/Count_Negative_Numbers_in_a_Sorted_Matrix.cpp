#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countNegatives(vector<vector<int>>& grid) {
          int rowSize = grid.size();
          int colSize = grid[0].size();
  
          int negCount = 0;
          for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
              for(int colIdx = 0; colIdx < colSize; colIdx++) {
                  if(grid[rowIdx][colIdx] < 0)
                      negCount++;
              }
          }
          return negCount;
      }
  };