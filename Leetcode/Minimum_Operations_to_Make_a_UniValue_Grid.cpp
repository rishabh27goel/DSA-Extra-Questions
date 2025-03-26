#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // Here my first intuition was binary search but it would work as all the numbers 
      // Which will have a remainder of zero as valid but we don't know how to shrink the 
      // binary search 
  
      // Think about sorting the grid
      // 1 23 25 27 67 -> 2 
      // 7 -> 3 + 1 + 8 -> 12
      // 9 -> 4 + 1 + 7 > 12
  
      // int minOperations(vector<vector<int>>& grid, int x) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     // cout.tie(NULL);
  
      //     int rowSize = grid.size();
      //     int colSize = grid[0].size();
  
      //     vector<int> elements;
      //     for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
      //         for(int colIdx = 0; colIdx < colSize; colIdx++) {
      //             elements.push_back(grid[rowIdx][colIdx]);
      //         }
      //     }
  
      //     sort(elements.begin(), elements.end());
  
  
      //     int size = elements.size();
      //     int candidate = elements[size / 2];
          
      //     int minOperations = 0;
      //     for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
      //         for(int colIdx = 0; colIdx < colSize; colIdx++) {
      //             if(abs(grid[rowIdx][colIdx] - candidate) % x == 0) 
      //                 minOperations += (abs(grid[rowIdx][colIdx] - candidate) / x);
      //             else
      //                 return -1;
      //         }
      //     }
      //     return minOperations;
      // }
  
      int minOperations(vector<vector<int>>& grid, int x) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int rowSize = grid.size();
          int colSize = grid[0].size();
  
          int size = rowSize * colSize;
  
          int freqCount[10001] = {0};
          for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
              for(int colIdx = 0; colIdx < colSize; colIdx++) {
                  freqCount[grid[rowIdx][colIdx]]++;
              }
          }
  
          int currCount = size;
          int candidate = -1;
  
          for(int c = 0; c < 10001; c++) {
              if(freqCount[c] == 0)   continue;
  
              currCount -= freqCount[c];
              if(currCount <= size / 2) {
                  candidate = c;
                  break;
              }
          }
  
          int minOperations = 0;
          for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
              for(int colIdx = 0; colIdx < colSize; colIdx++) {
                  if(abs(grid[rowIdx][colIdx] - candidate) % x == 0) 
                      minOperations += (abs(grid[rowIdx][colIdx] - candidate) / x);
                  else
                      return -1;
              }
          }
          return minOperations;
      }
  };