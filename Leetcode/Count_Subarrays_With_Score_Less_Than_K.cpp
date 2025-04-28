#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long countSubarrays(vector<int>& nums, long long k) {
          int size = nums.size();
  
          long long totalSubs = 0;
          long long prefixSum = 0;
  
          int leftIdx = 0;
          int currIdx = 0;
  
          while(currIdx < size) {
              prefixSum += nums[currIdx];
              while(leftIdx <= currIdx && prefixSum * (currIdx - leftIdx + 1) >= k) {
                  prefixSum -= nums[leftIdx];
                  leftIdx++;
              }
              totalSubs += (currIdx - leftIdx + 1);
              currIdx++;
          }
  
          return totalSubs;
      }
  };