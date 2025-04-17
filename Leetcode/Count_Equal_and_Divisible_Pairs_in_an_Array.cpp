#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countPairs(vector<int>& nums, int k) {
          int size = nums.size();
  
          int totalPairs = 0;
          for(int oneIdx = 0; oneIdx < size; oneIdx++) {
              for(int twoIdx = oneIdx + 1; twoIdx < size; twoIdx++) {
                  if((oneIdx * twoIdx) % k == 0 && nums[oneIdx] == nums[twoIdx])
                      totalPairs++;
              }
          }
          return totalPairs;
      }
  };