#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // int longestNiceSubarray(vector<int>& nums) {
      //     int size = nums.size();
  
      //     int longestSubarray = 0;
      //     for(int numIdx = 0; numIdx < size; numIdx++) {
      //         int currentSubarrayOr = 0;
      //         for(int currIdx = numIdx; currIdx < size; currIdx++) {
      //             // If they have nothing in common then we are good
      //             if((currentSubarrayOr & nums[currIdx]) == 0) {
      //                 int currLength = currIdx - numIdx + 1;
      //                 longestSubarray = max(longestSubarray, currLength);
      //             }
      //             // Else we can move forward
      //             else 
      //                 break;
  
      //             currentSubarrayOr |= nums[currIdx];
      //         }
      //     }
      //     return longestSubarray;
      // }
  
      int longestNiceSubarray(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
  
          int longestSubarray = 0;
          int currentWindowOr = 0;
  
          int startIdx = 0;
          int currIdx = 0;
  
          while(currIdx < size) {
              while(startIdx <= currIdx && (currentWindowOr & nums[currIdx]) != 0) {
                  currentWindowOr ^= nums[startIdx];
                  startIdx++;
              }
              longestSubarray = max(longestSubarray, currIdx - startIdx + 1);
              currentWindowOr |= nums[currIdx++];
          }
  
          return longestSubarray;
      }
  };