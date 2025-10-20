#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int finalValueAfterOperations(vector<string>& operations) {
          int size = operations.size();
  
          int valueX = 0;
          for(int idx = 0; idx < size; idx++) {
              string &current = operations[idx];
              if(current == "--X" || current == "X--")
                  valueX--;
              else
                  valueX++;
          }
          return valueX;
      }
  };