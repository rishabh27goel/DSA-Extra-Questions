#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // The tricky part is we have to first check if a valid triangle is possible
      string triangleType(vector<int>& nums) {
          int size = nums.size();
  
          // Valid triangle
          if(nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1]) {
              if(nums[0] == nums[1] && nums[1] == nums[2]) 
                  return "equilateral";
  
              if((nums[0] == nums[1]) || (nums[1] == nums[2]) || (nums[0] == nums[2]))
                  return "isosceles";
  
              return "scalene";
          }
          return "none";
      }
  };