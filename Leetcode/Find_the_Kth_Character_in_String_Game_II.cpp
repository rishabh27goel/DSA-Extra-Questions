#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int highestSetBit(long long currVal) {
          int bits = 0;
          while(currVal > 0) {
              bits++;
              currVal >>= 1;
          }
          return bits;
      }
  
      char kthCharacter(long long k, vector<int>& operations) {
          long long currVal = k;
          int operationCount = 0;
  
          while(currVal > 1) {
              int jump = ceil(log2(currVal));
              currVal -= (1LL << (jump - 1));
              operationCount += operations[jump - 1];
          }
  
          return (operationCount % 26) + 'a';
      }
  };