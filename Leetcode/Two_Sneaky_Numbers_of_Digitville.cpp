#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> getSneakyNumbers(vector<int>& nums) {
          int size = nums.size() - 2;
  
          int totalSum = 0;
          int totalSquareSum = 0;
  
          for(int &num : nums) {
              totalSum += num;
              totalSquareSum += (num * num);
          }
  
          int normalSum = totalSum - (size * (size - 1)) / 2;
          int squareSum = totalSquareSum - (size * (size - 1) * (2 * size - 1)) / 6;
  
          int numberOne = (normalSum - sqrt(2 * squareSum - normalSum * normalSum)) / 2;
          int numberTwo = (normalSum + sqrt(2 * squareSum - normalSum * normalSum)) / 2;
  
          return {numberOne, numberTwo};
      }
  };