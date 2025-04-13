#include <iostream>
using namespace std;

class Solution {
  public:
      int mod = 1e9 + 7;
  
      long long findMod(long long number, long long power) {
          long long result = 1;
          while(power > 0) {
              if(power & 1)
                  result = (result * number) % mod;
  
              number = (number * number) % mod;
              power >>= 1;
          }
          return result;
      }
  
      int countGoodNumbers(long long n) {
          long long totalWays = findMod(20, n / 2);
          
          if(n & 1)   totalWays = (totalWays * 5) % mod;
          return totalWays;
      }
  };