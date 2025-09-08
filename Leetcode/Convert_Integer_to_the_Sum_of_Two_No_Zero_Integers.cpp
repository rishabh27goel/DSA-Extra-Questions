#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool containsZero(int number) {
          while(number > 0) {
              int dig = number % 10;
              if(dig == 0)    
                  return true;
              
              number /= 10;
          }
          return false;
      }
  
      vector<int> getNoZeroIntegers(int n) {
          for(int c = 1; c <= n - 1; c++) {
              if(!containsZero(c) && !containsZero(n - c))
                  return {c, n - c};
          }
          return {};
      }
  };