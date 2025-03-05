#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long coloredCells(int n) {
          if(n == 1)
              return 1;
  
          long long totalCells = 1;
          totalCells += (4 * (1LL * (n - 1)));
          totalCells += (1LL * 2 * (n - 1) * (n - 2));
          return totalCells;
      }
  };