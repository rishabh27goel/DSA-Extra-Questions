#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
          int n = grid.size();
          
          bool exists[2502] = {0};
          int repeatedNumber = 1;
          int missingNumber = 1;
  
          for(int i = 0; i < n; i++) {
              for(int j = 0; j < n; j++) {
                  if(exists[grid[i][j]])  
                      repeatedNumber = grid[i][j];
  
                  exists[grid[i][j]] = true;
              }
          }
  
          for(int j = 1; j <= 2500; j++) {
              if(exists[j] == 0)
                  return {repeatedNumber, j};
          }
  
          return {-1, -1};
      }
  };