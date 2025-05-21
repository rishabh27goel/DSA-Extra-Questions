#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // Use first column to track zeroes only
      void setZeroes(vector<vector<int>>& matrix) {
          int rowSize = matrix.size();
          int colSize = matrix[0].size();
  
          bool firstColumn = false;
          for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
              if(matrix[rowIdx][0] == 0)
                  firstColumn = true;
  
              for(int colIdx = 1; colIdx < colSize; colIdx++) {
                  if(matrix[rowIdx][colIdx] == 0) {
                      matrix[rowIdx][0] = 0;
                      matrix[0][colIdx] = 0;
                  }
              }
          }
  
          for(int rowIdx = rowSize - 1; rowIdx >= 0; rowIdx--) {
              for(int colIdx = colSize - 1; colIdx >= 1; colIdx--) {
                  if(matrix[rowIdx][0] == 0 || matrix[0][colIdx] == 0) {
                      matrix[rowIdx][colIdx] = 0;
                  }
              }
  
              if(firstColumn)
                  matrix[rowIdx][0] = 0;
          }
      }
  };