#include <iostream>
using namespace std;

class Solution {
  public:
      long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
  
          long long totalSubs = 0;
          int prefixCount = 0;
  
          unordered_map<int, int> modCount;
          modCount[0] = 1;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              prefixCount += (nums[currIdx] % modulo == k);
              totalSubs += modCount[(prefixCount - k + modulo) % modulo];
              modCount[prefixCount % modulo]++;
          }
  
          return totalSubs;
      }
  };