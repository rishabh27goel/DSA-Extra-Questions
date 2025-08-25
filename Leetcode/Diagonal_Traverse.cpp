#include <vector>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
          int rowSize = matrix.size();
          int colSize = matrix[0].size();
      
          vector<int> diagonal;
          for(int moves = 0; moves < rowSize + colSize - 1; moves++) {
              if(moves % 2 == 0) {    // Upper movement
                  int start = min(moves, rowSize - 1);
                  int rowIdx = start; 
                  int colIdx = moves - start;
  
                  while(rowIdx >= 0 && colIdx < colSize) {
                      diagonal.push_back(matrix[rowIdx][colIdx]);
                      rowIdx--, colIdx++;
                  }
              }
              else {    // Lower movement
                  int start = min(moves, colSize - 1);
                  int rowIdx = moves - start; 
                  int colIdx = start;
  
                  while(rowIdx < rowSize && colIdx >= 0) {
                      diagonal.push_back(matrix[rowIdx][colIdx]);
                      rowIdx++, colIdx--;
                  }
              }
          }
          return diagonal;
      }
  };