#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
          int size = dimensions.size();
  
          int maxArea = 0;
          double maxDig = 0;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              int l = dimensions[currIdx][0];
              int b = dimensions[currIdx][1];
  
              double dig = sqrt(l * l + b * b);
              if(maxDig < dig) {
                  maxDig = dig;
                  maxArea = l * b;
              }
              else if(maxDig == dig)
                  maxArea = max(maxArea, l * b);
          }
          return maxArea;
      }
  };