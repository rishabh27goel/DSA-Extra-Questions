#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool checkPowersOfThree(int n) {
          while(n > 0) {
              // This will give us the number of times current power of 3 is needed
              // If it is 0 or 1 then fine otherwise return false
              if(n % 3 == 2)
                  return false;
  
              n /= 3;
          }
          return true;
      }
  };