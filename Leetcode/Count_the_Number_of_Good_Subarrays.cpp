#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long countGood(vector<int>& nums, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          long size = nums.size();
  
          long long totalGoodSubarrays = (size * (size + 1)) / 2;
          long long nonValidSubarrays = 0;
  
          unordered_map<int, int> freqMap;
          long goodSubarrays = 0;
  
          int leftIdx = 0;
          int currIdx = 0;
  
          while(currIdx < size) {
              goodSubarrays += freqMap[nums[currIdx]]++;
  
              while(leftIdx <= currIdx && goodSubarrays >= k) {
                  goodSubarrays -= --freqMap[nums[leftIdx]];
                  leftIdx++;
              }
  
              nonValidSubarrays += (currIdx - leftIdx + 1);
              currIdx++;
          }
  
          return totalGoodSubarrays - nonValidSubarrays;
      }
  };