#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int getBitCount(int k) {
          int bits = 0;
          while(k > 0) {
              bits++;    
              k >>= 1;
          }
          return bits;
      }   
      int longestSubsequence(string str, int k) {
          int size = str.size();
  
          // To avoid 1000 bits at max
          int bitLimit = getBitCount(k);
          int bitCount = 0;
  
          long mask = 0;        
          for(int idx = 0; idx < size; idx++) {
              char currChar = str[size - idx - 1];
              if(currChar == '1') {
                  if(idx < bitLimit && mask + (1 << idx) <= k) {
                      mask += (1 << idx);
                      bitCount++;
                  }
              }
              else {
                  bitCount++;
              }
          }
  
          return bitCount;
      }
  };