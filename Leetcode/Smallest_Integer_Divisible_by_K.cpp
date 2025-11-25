#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int smallestRepunitDivByK(int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int remainder = 0;
          for(int length = 1; length <= k; length++) {
              remainder = (remainder * 10 + 1) % k;     
              if(remainder == 0)
                  return length;
          }   
          return -1;
      }
  };