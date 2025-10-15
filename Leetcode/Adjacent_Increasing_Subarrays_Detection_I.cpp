#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool hasIncreasingSubarrays(vector<int>& nums, int k) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
          
          int lastLength = -1;
          int currIdx = 0; 
  
          while(currIdx < size) {
              int lastNum = nums[currIdx++];
              int length = 1;
  
              while(currIdx < size && lastNum < nums[currIdx]) {
                  lastNum = nums[currIdx];
                  length++, currIdx++;
              }
              
              // Adjacent subarrays exists
              if(length >= 2 * k)  return true;
              if(lastLength >= k && length >= k)  return true;
              lastLength = length;        
          }
          return false; 
      }
  };