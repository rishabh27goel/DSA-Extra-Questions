#include <iostream>
using namespace std;

class Solution {
  public:
      int maxDifference(string str) {
          int size = str.size();
  
          int charCount[26] = {0};
          for(int idx = 0; idx < size; idx++) {
              charCount[str[idx]-'a']++;
          }
  
          int maxOdd = 0;
          int minEven = 200;
  
          for(int c = 0; c < 26; c++) {
              if(charCount[c] == 0)
                  continue;
  
              if(charCount[c] % 2 == 1)
                  maxOdd = max(maxOdd, charCount[c]);
              else
                  minEven = min(minEven, charCount[c]);
          }
  
          return maxOdd - minEven;
      }
  };