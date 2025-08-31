#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool checkCurrentCell(int size, vector<vector<char>> &board, int rowIdx, int colIdx) {
          char target = board[rowIdx][colIdx];
  
          for(int currIdx = 0; currIdx < size; currIdx++) {   // Check if row is valid
              if(currIdx == colIdx)   continue;
  
              if(board[rowIdx][currIdx] == target)
                  return false;
          }
  
          for(int currIdx = 0; currIdx < size; currIdx++) {   // Check if column is valid
              if(currIdx == rowIdx)   continue;
  
              if(board[currIdx][colIdx] == target)
                  return false;
          }
  
          int rowStart = (rowIdx / 3) * 3;
          int colStart = (colIdx / 3) * 3;
  
          for(int row = rowStart; row < rowStart + 3; row++) {
              for(int col = colStart; col < colStart + 3; col++) {
                  if(row == rowIdx && col == colIdx)  continue;
  
                  if(board[row][col] == target)
                      return false;
              }   
          }
          return true;
      }
  
      bool isValidSudoku(vector<vector<char>>& board) {
          int size = board.size();
  
          for(int rowIdx = 0; rowIdx < size; rowIdx++) {
              for(int colIdx = 0; colIdx < size; colIdx++) {
                  if(board[rowIdx][colIdx] != '.') {      // A filled cell
                      if(!checkCurrentCell(size, board, rowIdx, colIdx))
                          return false;
                  }
              }
          }
          return true;
      }
  };