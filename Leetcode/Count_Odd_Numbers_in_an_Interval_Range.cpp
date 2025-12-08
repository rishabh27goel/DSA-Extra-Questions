#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countOdds(int low, int high) {  
          int diff = high - low;
  
          if(diff % 2 == 0) {
              if((low & 1))   return (diff / 2) + 1;
              else   return diff / 2;
          }
          return (diff / 2) + 1;
      }
  };