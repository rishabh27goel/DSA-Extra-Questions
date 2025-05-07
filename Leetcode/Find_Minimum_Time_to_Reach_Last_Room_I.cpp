#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int minTimeToReach(vector<vector<int>>& moveTime) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int rowSize = moveTime.size();
          int colSize = moveTime[0].size();
  
          priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> minHeap;
          minHeap.push({0, 0});
          moveTime[0][0] = -1;
  
          while(!minHeap.empty()) {
              auto currPair = minHeap.top();
              minHeap.pop();
  
              long currTime = currPair.first;
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
  
                  if(x >= 0 && y >= 0 && x < rowSize && y < colSize && moveTime[x][y] >= 0) {
                      long nextTime = max(1L * currTime, 1L * moveTime[x][y]) + 1;
                      minHeap.push({nextTime, x * colSize + y});
                      moveTime[x][y] = -1;
                  }
              }
          }
  
          return 0;
      }
  };