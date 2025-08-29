#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      // vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
      //     ios_base::sync_with_stdio(false);
      //     // cin.tie(NULL);
      //     cout.tie(NULL);
  
      //     int size = grid.size();
  
      //     for(int currIdx = 0; currIdx < size; currIdx++) {
      //         vector<int> values;
      //         int rowIdx = currIdx;
      //         int colIdx = 0;
  
      //         while(rowIdx < size && colIdx < size) {
      //             values.push_back(grid[rowIdx][colIdx]);
      //             rowIdx++, colIdx++;
      //         }
  
      //         // Sort the values array
      //         sort(values.begin(), values.end(), greater<int> ());
  
      //         int idx = 0;
      //         rowIdx = currIdx;
      //         colIdx = 0;
  
      //         while(rowIdx < size && colIdx < size) {
      //             grid[rowIdx][colIdx] = values[idx];
      //             idx++, rowIdx++, colIdx++;
      //         }
      //     }
  
      //     for(int currIdx = 1; currIdx < size; currIdx++) {
      //         vector<int> values;
      //         int rowIdx = 0;
      //         int colIdx = currIdx;
  
      //         while(rowIdx < size && colIdx < size) {
      //             values.push_back(grid[rowIdx][colIdx]);
      //             rowIdx++, colIdx++;
      //         }
  
      //         // Sort the values array
      //         sort(values.begin(), values.end());
  
      //         int idx = 0;
      //         rowIdx = 0;
      //         colIdx = currIdx;
  
      //         while(rowIdx < size && colIdx < size) {
      //             grid[rowIdx][colIdx] = values[idx];
      //             idx++, rowIdx++, colIdx++;
      //         }
      //     }
      //     return grid;
      // }
  
      vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = grid.size();
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              priority_queue<int> pq;
              int rowIdx = currIdx;
              int colIdx = 0;
  
              while(rowIdx < size && colIdx < size) {
                  pq.push(grid[rowIdx][colIdx]);
                  rowIdx++, colIdx++;
              }
  
              rowIdx = currIdx;
              colIdx = 0;
  
              while(rowIdx < size && colIdx < size) {
                  grid[rowIdx][colIdx] = pq.top();
                  pq.pop();
                  rowIdx++, colIdx++;
              }
          }
  
          for(int currIdx = 1; currIdx < size; currIdx++) {
              priority_queue<int, vector<int>, greater<int>> pq;
              int rowIdx = 0;
              int colIdx = currIdx;
  
              while(rowIdx < size && colIdx < size) {
                  pq.push(grid[rowIdx][colIdx]);
                  rowIdx++, colIdx++;
              }
  
              rowIdx = 0;
              colIdx = currIdx;
  
              while(rowIdx < size && colIdx < size) {
                  grid[rowIdx][colIdx] = pq.top();
                  pq.pop();
                  rowIdx++, colIdx++;
              }
          }
          return grid;
      }
  };