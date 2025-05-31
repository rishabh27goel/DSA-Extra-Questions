#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int snakesAndLadders(vector<vector<int>>& board) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int boardSize = board.size();
  
          int visited[boardSize * boardSize];
          memset(visited, false, 4 * boardSize * boardSize);
  
          queue<int> moves;
          moves.push(0);
  
          int dieRolls = 0;
          visited[0] = true;
  
          while(!moves.empty()) {
              int size = moves.size();
              while(size--) {
                  int currMove = moves.front();
                  moves.pop();
  
                  if(currMove == (boardSize * boardSize) - 1)
                      return dieRolls;
  
                  int row = currMove / boardSize;
                  int col = currMove % boardSize;
  
                  if(row % 2 == 1)   col = (boardSize - 1 - col);
                  row = (boardSize - 1 - row);
  
                  for(int next = 1; next <= 6; next++) {
                      if(currMove + next >= boardSize * boardSize)    
                          break;
  
                      int nextMove = currMove + next;
                      int nextRow = nextMove / boardSize;
                      int nextCol = nextMove % boardSize;
  
                      if(nextRow % 2 == 1)   nextCol = (boardSize - 1 - nextCol);
                      nextRow = (boardSize - 1 - nextRow);
  
                      int newMove = board[nextRow][nextCol] == -1 ? nextMove : (board[nextRow][nextCol] - 1);
                      if(visited[newMove] == false) {
                          moves.push(newMove);
                          visited[newMove] = true;
                      }
                  }
              }
              dieRolls++;
          }
          
          return -1; 
      }
  };