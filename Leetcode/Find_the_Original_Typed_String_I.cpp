#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int possibleStringCount(string word) {
          int size = word.size();
  
          int totalCount = 1;
          int idx = 0;
  
          while(idx < size) {
              int count = 0;
              char ch = word[idx];
              
              while(idx < size && ch == word[idx]) {
                  count++, idx++;
              }
  
              totalCount += (count - 1);
          }
          
          return totalCount;
      }
  };