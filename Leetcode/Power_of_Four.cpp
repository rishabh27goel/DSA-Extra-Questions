#include <iostream>
using namespace std;

class Solution {
  public:
      // First was the check for power of 2
      // Second to check the odd position values (1 -> 00001, 4 -> 00100, 16 -> 10000)
  
      bool isPowerOfFour(int n) {
          if(n <= 0)
              return false;
  
          return (n & (n - 1)) == 0 && (n & 0x55555555);
      }
  };