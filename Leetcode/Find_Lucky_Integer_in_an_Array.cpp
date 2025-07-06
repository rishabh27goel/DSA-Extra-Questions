#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int findLucky(vector<int>& arr) {
          int size = arr.size();
          
          int freqMap[501];
          for(int idx = 0; idx < size; idx++) {
              freqMap[arr[idx]]++;
          }
  
          for(int c = 500; c >= 1; c--){
              if(freqMap[c] == c)
                  return c;
          }
          return -1;
      }
  };