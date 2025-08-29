#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long flowerGame(int n, int m) {
          long long firstLaneOdd = (n + 1) / 2;
          long long firstLaneEven = n - firstLaneOdd;
  
          long long secondLaneOdd = (m + 1) / 2;
          long long secondLaneEven = m - secondLaneOdd;
          
          return (firstLaneOdd * secondLaneEven) + (firstLaneEven * secondLaneOdd);
      }
  };