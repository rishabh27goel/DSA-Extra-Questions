#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int findNumbers(vector<int>& nums) {
          int size = nums.size();
  
          int evenCount = 0;
          for(int idx = 0; idx < size; idx++) {
              int digCount = log10(nums[idx]);
              if(digCount & 1)
                  evenCount++;
          }
  
          return evenCount;
      }
  };