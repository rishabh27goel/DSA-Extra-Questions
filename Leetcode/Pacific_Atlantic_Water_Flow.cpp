#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int xPos[4] = {1, -1, 0, 0};
      int yPos[4] = {0, 0, 1, -1};
  
      void traversePoints(int rowSize, int colSize, vector<vector<int>> &heights, vector<vector<int>> &ocean, int rowIdx, int colIdx) {
          if(ocean[rowIdx][colIdx])   return;
          ocean[rowIdx][colIdx] = true;
  
          for(int k = 0; k < 4; k++) {
              int x = xPos[k] + rowIdx;
              int y = yPos[k] + colIdx;
  
              if(x >= 0 && y >= 0 && x < rowSize && y < colSize && heights[x][y] >= heights[rowIdx][colIdx]) {
                  traversePoints(rowSize, colSize, heights, ocean, x, y);
              }
          }
      }
  
      vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int rowSize = heights.size();
          int colSize = heights[0].size();
  
          vector<vector<int>> pacific(rowSize, vector<int> (colSize, false));
          for(int currIdx = 0; currIdx < rowSize; currIdx++) {   
              traversePoints(rowSize, colSize, heights, pacific, currIdx, 0);
          }
          for(int currIdx = 1; currIdx < colSize; currIdx++) {
              traversePoints(rowSize, colSize, heights, pacific, 0, currIdx);
          }
  
          vector<vector<int>> atlantic(rowSize, vector<int> (colSize, false));
          for(int currIdx = 0; currIdx < rowSize; currIdx++) {
              traversePoints(rowSize, colSize, heights, atlantic, currIdx, colSize - 1);
          }
          for(int currIdx = colSize - 2; currIdx >= 0; currIdx--) {
              traversePoints(rowSize, colSize, heights, atlantic, rowSize - 1, currIdx);
          }
  
          vector<vector<int>> coords;
          for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
              for(int colIdx = 0; colIdx < colSize; colIdx++) {
                  if(pacific[rowIdx][colIdx] && atlantic[rowIdx][colIdx]) {
                      coords.push_back({rowIdx, colIdx});
                  }
              }
          }
          return coords;
      }
  };