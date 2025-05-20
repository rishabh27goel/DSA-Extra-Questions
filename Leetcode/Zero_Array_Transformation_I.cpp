#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
          int size = nums.size();
  
          vector<long> trackCount(size + 1, 0);
          for(int idx = 0; idx < queries.size(); idx++) {
              int l = queries[idx][0];
              int r = queries[idx][1];
  
              trackCount[l]++;
              trackCount[r + 1]--;
          }
  
          long prefix = 0;
          for(int idx = 0; idx < size; idx++) {
              prefix += trackCount[idx];
  
              if(nums[idx] - prefix > 0)
                  return false;
          }
  
          return true;
      }
  };