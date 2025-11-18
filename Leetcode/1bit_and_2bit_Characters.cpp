#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool isOneBitCharacter(vector<int>& bits) {
          int size = bits.size();
  
          int lastChar = -1;
          int currIdx = 0;
  
          while(currIdx < size) {
              if(bits[currIdx] == 0) {
                  lastChar = 0;
                  currIdx++;
              }
              else {
                  lastChar = 1;
                  currIdx += 2;
              }
          }
          return lastChar == 0;
      }
  };