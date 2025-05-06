#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> buildArray(vector<int>& nums) {
          int size = nums.size();
  
          vector<int> answer;
          for(int idx = 0; idx < size; idx++) 
              answer.push_back(nums[nums[idx]]);
          
          return answer;
      }
  };