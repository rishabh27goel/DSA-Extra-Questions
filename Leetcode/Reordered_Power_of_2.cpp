#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> getDigitArray(int number) {
          vector<int> digArray(10, 0);
          while(number > 0) {
              digArray[number % 10]++;
              number /= 10;
          }
          return digArray;
      }
  
      bool reorderedPowerOf2(int n) {
          vector<int> targetDigArray = getDigitArray(n);
          int mask = (1 << 30);
  
          while(mask > 0) {
              vector<int> currentDigArray = getDigitArray(mask);
              if(targetDigArray == currentDigArray)
                  return true;
  
              mask >>= 1;
          }
          return false;
      }
  };