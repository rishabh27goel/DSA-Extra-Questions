#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
      vector<int> sumZero(int n) {
          int size = (n / 2);
  
          vector<int> output;
          for(int c = 1; c <= size; c++) {
              output.push_back(-c);
              output.push_back(c);
          }
  
          if(n & 1)  output.push_back(0);
          return output;
      }
  };