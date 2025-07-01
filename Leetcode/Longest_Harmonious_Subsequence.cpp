#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int findLHS(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          // Sort the array
          sort(nums.begin(), nums.end());
  
          int longestSub = 0;
          int currIdx = 0;
  
          int prevVal = INT_MIN;
          int prevCount = 0;
  
          while(currIdx < size) {
              int currVal = nums[currIdx];
              int count = 0;
  
              while(currIdx < size && currVal == nums[currIdx]) {
                  count++, currIdx++;
              }
  
              if(prevVal + 1 == currVal)  
                  longestSub = max(longestSub, prevCount + count);
  
              prevVal = currVal;
              prevCount = count;
          }
  
          return longestSub;
      }
  };