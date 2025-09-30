#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int triangularSum(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
          int end = size - 2;
  
          while(end >= 0) {
              for(int currIdx = 0; currIdx <= end; currIdx++) {
                  nums[currIdx] = (nums[currIdx] + nums[currIdx + 1]) % 10;
              }
              end--;
          }
          return nums[0];   
      }
  };