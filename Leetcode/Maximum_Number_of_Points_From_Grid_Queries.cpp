#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      /*
          Given : grid -> n * m
                  queries -> k
  
          1. Start from top - left find the maximum points you can reach
          2. If we observe that the larger the number is more points it can cover
             means we can start from smaller -> larger in order
  
          3. If we use the brute force it will be TLE (n * m * k) -> 1e9
      */
  
      // We will use minHeap - this will help us to stop our execution when we have 
      // covered all the points for current queries
  
      /*
          Step 1 : Sort the queries in ascending order
          Step 2 : Create minHeap <value, index> 
      
      */
  
      int pointsCovered = 0;
  
      void bfsTraverseGrid(int rowSize, int colSize, vector<vector<int>> &grid, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &cellMinHeap, int target) {
          if(cellMinHeap.empty())
              return;
  
          int xPos[4] = {1, -1, 0, 0};
          int yPos[4] = {0, 0, 1, -1};
  
          while(!cellMinHeap.empty()) {
              auto currInfo = cellMinHeap.top();
  
              if(currInfo.first >= target)  return;
              cellMinHeap.pop();
          
              pointsCovered++;
  
              int rowIdx = currInfo.second / colSize;
              int colIdx = currInfo.second % colSize;
  
              for(int k = 0; k < 4; k++) {
                  int x = xPos[k] + rowIdx;
                  int y = yPos[k] + colIdx;
  
                  if(x >= 0 && y >= 0 && x < rowSize && y < colSize && grid[x][y] != -1) {
                      cellMinHeap.push(make_pair(grid[x][y], x * colSize + y));   
                      grid[x][y] = -1;
                  }   
              }
  
          }
      }
      vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int rowSize = grid.size();
          int colSize = grid[0].size();
  
          vector<pair<int, int>> sortedQueries;
          for(int idx = 0; idx < queries.size(); idx++) {
              sortedQueries.push_back(make_pair(queries[idx], idx));
          }
  
          // Sort the queries array
          sort(sortedQueries.begin(), sortedQueries.end());
  
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cellMinHeap;
          cellMinHeap.push(make_pair(grid[0][0], 0));
          grid[0][0] = -1;
  
          vector<int> answer(queries.size());
          for(auto &current : sortedQueries) {
              bfsTraverseGrid(rowSize, colSize, grid, cellMinHeap, current.first);
              answer[current.second] = pointsCovered;
          }
          return answer;
      }
  };