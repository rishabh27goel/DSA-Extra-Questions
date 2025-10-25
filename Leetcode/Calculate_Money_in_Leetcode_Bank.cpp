#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int fixedSum(int times) {
          if(times == 0)  return 0;
  
          return (28 * times) + (times * (times - 1) * 7) / 2; 
      }
  
      int leftSum(int time, int previousWeek) {
          if(time == 0)  return 0;
  
          int half = ((time * (time + 1)) / 2);
          return half + (time * previousWeek);
      }
  
      int totalMoney(int n) {
          int fixed = fixedSum(n / 7);
          int left = leftSum(n % 7, n / 7);
  
          return fixed + left;
      }
  };