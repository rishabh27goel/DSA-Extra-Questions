#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maxArea(vector<int>& height) {
          int size = height.size();
  
          int maxAreaOutput = 0;
          int startIdx = 0;
          int endIdx = size - 1;
  
          while(startIdx <= endIdx) {
              if(height[startIdx] <= height[endIdx]) {
                  maxAreaOutput = max(maxAreaOutput, (endIdx - startIdx) * height[startIdx]);
                  startIdx++;
              }
              else {
                  maxAreaOutput = max(maxAreaOutput, (endIdx - startIdx) * height[endIdx]);
                  endIdx--;
              }
          }
          return maxAreaOutput;
      }
  };