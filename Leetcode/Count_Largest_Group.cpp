#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countLargestGroup(int n) {
          vector<int> groupCount(40, 0);
          int maxGroup = 0;
          int largestCount = 0;
  
          for(int current = 1; current <= n; current++) {
              int currNum = current;
              int digSum = 0;
  
              while(currNum > 0) {
                  digSum += currNum % 10;
                  currNum /= 10;
              }
  
              if(maxGroup < ++groupCount[digSum]) {
                  maxGroup = groupCount[digSum];
                  largestCount = 1;
              }
              else if(maxGroup == groupCount[digSum]) {
                  largestCount++;
              }
          }
  
          return largestCount;
      }
  };