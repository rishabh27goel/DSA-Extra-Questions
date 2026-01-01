#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> plusOne(vector<int>& digits) {
          int size = digits.size();
  
          reverse(digits.begin(), digits.end());
  
          int carry = 1;
          int currIdx = 0;
          
          while(currIdx < size) {
              int currDig = (digits[currIdx] + carry);
              digits[currIdx] = currDig % 10;
              carry = currDig / 10;
              currIdx++;
          }
  
          if(carry > 0)  digits.push_back(carry);
  
          reverse(digits.begin(), digits.end());
          return digits;
      }
  };