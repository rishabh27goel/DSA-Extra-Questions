#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool isValidCell(int size, vector<vector<char>> &board, int rowIdx, int colIdx, char target) {
          // Check the current row
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(board[rowIdx][currIdx] == target)
                  return false;
          }
  
          // Check the current column
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(board[currIdx][colIdx] == target)
                  return false;
          }
  
          int rowStart = (rowIdx / 3) * 3;
          int colStart = (colIdx / 3) * 3;
  
          for(int row = rowStart; row < rowStart + 3; row++) {
              for(int col = colStart; col < colStart + 3; col++) {
                  if(board[row][col] == target)
                      return false;
              }    
          }
          return true;
      }
  
      bool fillSudokuBoard(int size, vector<vector<char>> &board, int rowIdx, int colIdx) {
          if(colIdx == size) {
              rowIdx = rowIdx + 1;
              colIdx = 0;
          }
  
          if(rowIdx == size)
              return true;
  
          // Current Cell is filled
          if(board[rowIdx][colIdx] != '.')
              return fillSudokuBoard(size, board, rowIdx, colIdx + 1);
      
  
          for(char val = '1'; val <= '9'; val++) {
              if(isValidCell(size, board, rowIdx, colIdx, val)) {
                  board[rowIdx][colIdx] = val;
                  if(fillSudokuBoard(size, board, rowIdx, colIdx + 1))
                      return true;
                  
                  // Backtracking step
                  board[rowIdx][colIdx] = '.';
              }
          }
          return false;
      }
  
      void solveSudoku(vector<vector<char>>& board) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = board.size();
              
          fillSudokuBoard(size, board, 0, 0);
          return;
      }
  };