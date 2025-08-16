#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maximum69Number (int num) {
          vector<int> digits;
          while(num > 0) {
              digits.push_back(num % 10);
              num /= 10;
          }
  
          for(int idx = digits.size() - 1; idx >= 0; idx--) {
              if(digits[idx] == 6) {
                  digits[idx] = 9;
                  break;
              }
          }
  
          int maxNum = 0;
          for(int idx = digits.size() - 1; idx >= 0; idx--) {
              maxNum = (maxNum * 10) + digits[idx];
          }
          return maxNum;
      }
  };