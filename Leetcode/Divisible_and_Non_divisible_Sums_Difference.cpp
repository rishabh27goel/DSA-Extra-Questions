#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int differenceOfSums(int n, int m) {
          int totalSum = (n * (n + 1)) / 2;
          int number = (n / m);
  
          int nums2 = (number * (2 * m + (number - 1) * m)) / 2;
          int nums1 = totalSum - nums2;
  
          return nums1 - nums2;
      }
  };