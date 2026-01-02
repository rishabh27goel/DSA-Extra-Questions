#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // It gets easy because the question says n + 1 unique elements
      // If we spread n items in 2 * n array
      // We will have at least one pair with distance <= 2
  
      int repeatedNTimes(vector<int>& nums) {
          int n = nums.size();
         
          for(int idx = 0; idx < n - 2; idx++) 
              if(nums[idx] == nums[idx + 1] || nums[idx] == nums[idx + 2])
                  return nums[idx];
          
          return nums[n - 1];
      }
  };