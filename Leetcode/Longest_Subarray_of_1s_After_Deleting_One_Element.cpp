#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int longestSubarray(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          int deletions = 0;
          int endIdx = 0;
          int startIdx = 0;
  
          int maxLength = 0;
          while(endIdx < size) {
              deletions += (nums[endIdx] == 0);
              while(startIdx <= endIdx && deletions > 1) {
                  deletions -= (nums[startIdx] == 0);
                  startIdx++;
              }
  
              maxLength = max(maxLength, endIdx - startIdx);
              endIdx++;
          }
          return maxLength;
      }
  };