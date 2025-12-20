#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
      int minDeletionSize(vector<string>& strs) {
          ios_base::sync_with_stdio(false);
  
          int rowSize = strs.size();
          int colSize = strs[0].size();
  
          int deleteCount = 0;
          for(int colIdx = 0; colIdx < colSize; colIdx++) {
              char currChar = strs[0][colIdx];
              int rowIdx = 0;
  
              while(rowIdx < rowSize && currChar <= strs[rowIdx][colIdx]) {
                  currChar = strs[rowIdx][colIdx];
                  rowIdx++;
              }
              if(rowIdx != rowSize)   deleteCount++;
          }
          return deleteCount;
      }
  };