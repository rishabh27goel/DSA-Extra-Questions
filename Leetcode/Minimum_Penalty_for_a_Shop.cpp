#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int bestClosingTime(string customers) {
          int n = customers.size();
  
          int currValue = 0;
          for(int currIdx = 0; currIdx < n; currIdx++) 
              currValue += (customers[currIdx] == 'N');
          
  
          int minPenalty = currValue;
          int earliestHour = n;
  
          for(int currIdx = n - 1; currIdx >= 0; currIdx--) {
              currValue -= (customers[currIdx] == 'N');
              currValue += (customers[currIdx] == 'Y');
  
              if(minPenalty >= currValue) {
                  earliestHour = currIdx;
                  minPenalty = currValue;
              }
          }
          return earliestHour;
      }
  };