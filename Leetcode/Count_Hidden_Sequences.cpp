#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int numberOfArrays(vector<int>& differences, int lower, int upper) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = differences.size();
  
          long maxNum = 0;
          long minNum = 0;
          long currNum = 0;
          
          for(int currIdx = 0; currIdx < size; currIdx++) {
              currNum += differences[currIdx];
              maxNum = max(maxNum, currNum);
              minNum = min(minNum, currNum);
          }
  
          long difference = lower - minNum;
          maxNum += difference;
  
          return max(upper - maxNum + 1, 0L);
      }
  };