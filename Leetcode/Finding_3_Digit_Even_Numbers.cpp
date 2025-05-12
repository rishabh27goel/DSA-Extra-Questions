#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> findEvenNumbers(vector<int>& digits) {
          int size = digits.size();
  
          int digitCount[10] = {0};
          for(int idx = 0; idx < size; idx++) {
              digitCount[digits[idx]]++;
          }
  
          vector<int> numbers;
          for(int current = 100; current <= 999; current += 2) {
              int currDigCount[10] = {0};
              int tmp = current;
  
              currDigCount[tmp % 10]++;
              tmp /= 10;
  
              currDigCount[tmp % 10]++;
              tmp /= 10;
  
              currDigCount[tmp % 10]++;
              tmp /= 10;
  
              bool valid = true;
              for(int c = 0; c < 10; c++) {
                  if(currDigCount[c] == 0)  continue;
  
                  if(currDigCount[c] > digitCount[c]) {
                      valid = false;
                      break;
                  }
              }   
              if(valid)   numbers.push_back(current);
          }
          return numbers; 
      }
  };