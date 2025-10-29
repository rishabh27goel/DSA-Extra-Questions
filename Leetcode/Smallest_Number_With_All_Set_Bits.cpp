#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int smallestNumber(int n) {
          int total = 0;
          int mask = 1;
  
          while(n > 0) {
              total = (total | mask);
              mask <<= 1;
              n >>= 1;
          }
          return total;
      }
  };