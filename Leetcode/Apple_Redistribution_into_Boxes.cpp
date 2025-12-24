#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
          sort(capacity.begin(), capacity.end(), greater<int> ());
  
          int totalSum = 0;
          for(int currIdx = 0; currIdx < apple.size(); currIdx++)
              totalSum += apple[currIdx];
  
          int minCount = 1;
          for(int currIdx = 0; currIdx < capacity.size(); currIdx++) {
              totalSum -= capacity[currIdx];
              if(totalSum <= 0)   return minCount;
              minCount++;
          }
          return minCount;
      }
  };