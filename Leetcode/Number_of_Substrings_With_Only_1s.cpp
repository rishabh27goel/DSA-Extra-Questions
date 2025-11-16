#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int numSub(string str) {
          int size = str.size();
          int mod = 1e9 + 7;
  
          long totalSubs = 0;
          int currIdx = 0;
  
          while(currIdx < size) {
              if(str[currIdx] == '0') {
                  currIdx++;
              }
              else {
                  int count = 0;
                  while(currIdx < size && str[currIdx] == '1') {
                      count++;
                      totalSubs = (totalSubs + count) % mod;
                      currIdx++;
                  }
              }
          }
          return totalSubs;
      }
  };