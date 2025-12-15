#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long getDescentPeriods(vector<int>& prices) {
          int size = prices.size();
  
          long long totalPeriods = 0;
          int currIdx = 0;
  
          while(currIdx < size) {
              int currVal = prices[currIdx++];
              int count = 1;
              totalPeriods += count;
  
              while(currIdx < size && currVal - 1 == prices[currIdx]) {
                  count++;
                  totalPeriods += count;
                  
                  currVal = prices[currIdx];
                  currIdx++;
              }
          }
          return totalPeriods;
      }
  };