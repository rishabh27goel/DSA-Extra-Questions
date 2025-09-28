#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int largestPerimeter(vector<int>& nums) {
          int size = nums.size();
  
          // Sort the array
          sort(nums.begin(), nums.end());
      
          int largest = 0;
          for(int currIdx = 0; currIdx < size - 2; currIdx++) {
              if(nums[currIdx] + nums[currIdx + 1] > nums[currIdx + 2]) {
                  largest = max(largest, nums[currIdx] + nums[currIdx + 1] + nums[currIdx + 2]);
              }
          }
          return largest;
      }
  };