#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int minTimeToReach(vector<vector<int>>& moveTime) {
          int rowSize = moveTime.size();
          int colSize = moveTime[0].size();
  
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
          minHeap.push({0, 0});
          moveTime[0][0] = -1;
  
          while(!minHeap.empty()) {
              auto currPair = minHeap.top();
              minHeap.pop();
  
              int currTime = currPair.first;
              int node = currPair.second;
  
              int row = node / colSize;
              int col = node % colSize;
  
              if(row == rowSize - 1 && col == colSize - 1)
                  return currTime;
  
              int xPos[4] = {1, 0, -1, 0};
              int yPos[4] = {0, 1, 0, -1};
  
              for(int k = 0; k < 4; k++) {
                  int x = xPos[k] + row;
                  int y = yPos[k] + col;
  
                  if(x >= 0 && x < rowSize && y >= 0 && y < colSize && moveTime[x][y] >= 0) {
                      int nextTime = max(moveTime[x][y], currTime) + ((row + col) % 2 == 0 ? 1 : 2);
                      minHeap.push({nextTime, x * colSize + y});
                      moveTime[x][y] = -1;
                  }
              }
          }
  
          return 0;
      }
  };