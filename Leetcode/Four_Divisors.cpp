#include <iostream>
#include <vectoe>
using namespace std;

class Solution {
  public:
      int sumFourDivisors(vector<int>& nums) {
          int size = nums.size();
  
          int divSum = 0;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              int number = nums[currIdx];
              int totalSum = 0;
              int divisors = 0;
  
              for(int n = 1; n * n <= number; n++) {
                  if(number % n != 0)  continue;
  
                  if(n * n == number) {
                      divisors++;
                      totalSum += n;
                  }
                  else {
                      divisors += 2;
                      totalSum += (n + (number / n));
                  }
              }
              if(divisors == 4)   divSum += totalSum;
          }
          return divSum;
      }
  };