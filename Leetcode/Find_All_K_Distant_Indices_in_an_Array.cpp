#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
          int size = nums.size();
  
          vector<int> range(size + 1, 0);
          for(int idx = 0; idx < size; idx++) {
              if(nums[idx] == key) {
                  int leftIdx = max(0, idx - k);
                  int rightIdx = min(size, idx + k + 1);
  
                  range[leftIdx]++;
                  range[rightIdx]--;
              }
          }
  
          vector<int> distantIdx;
          int prefix = 0;
  
          for(int idx = 0; idx < size; idx++) {
              prefix += range[idx];
              if(prefix > 0)  distantIdx.push_back(idx);
          }
          return distantIdx;
      }
  };