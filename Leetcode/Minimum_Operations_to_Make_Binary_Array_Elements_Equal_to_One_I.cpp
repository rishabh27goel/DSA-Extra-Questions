#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minOperations(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
  
          int operations = 0;
          for(int numIdx = 0; numIdx <= size - 3; numIdx++) {
              if(nums[numIdx] == 1)   continue;
  
              operations++;
              for(int nextIdx = numIdx; nextIdx < numIdx + 3; nextIdx++) {
                  nums[nextIdx] = !nums[nextIdx];
              }
          }
  
          if(nums[size - 1] == 0 || nums[size - 2] == 0)
              return -1;
  
          return operations;
      }
  };