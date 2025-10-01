#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
      int numWaterBottles(int numBottles, int numExchange) {
          int totalBottles = numBottles;
          int emptyBottles = numBottles;
          int remainingBottles = 0;
  
          while(emptyBottles + remainingBottles >= numExchange) {
              int currBottles = ((emptyBottles + remainingBottles) / numExchange);
              totalBottles += currBottles;
  
              remainingBottles = ((emptyBottles + remainingBottles) % numExchange);
              emptyBottles = currBottles;
          }
          return totalBottles;
      }
  };