#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // vector<vector<int>> divideArray(vector<int>& nums, int k) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     cout.tie(NULL);
  
      //     int size = nums.size();
  
      //     // Sort the array
      //     sort(nums.begin(), nums.end());
  
      //     vector<vector<int>> result;
      //     for(int currIdx = 0; currIdx < size; currIdx += 3) {
      //         if(nums[currIdx + 2] - nums[currIdx] <= k) {
      //             vector<int> currArr;
      //             currArr.push_back(nums[currIdx]);
      //             currArr.push_back(nums[currIdx + 1]);
      //             currArr.push_back(nums[currIdx + 2]);
      //             result.push_back(currArr);
      //         }
      //         else 
      //             return {};
      //     }
      //     return result;
      // }
  
      vector<vector<int>> divideArray(vector<int>& nums, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
          int maxSize = *max_element(nums.begin(), nums.end()) + 1;
  
          vector<int> freq(maxSize, 0);
          for(int &num : nums)
              freq[num]++;
  
          vector<vector<int>> result(size / 3, vector<int> (3));
          int currIdx = 0;
  
          for(int outerIdx = 0; outerIdx < (size / 3); outerIdx++) {
              for(int c = 0; c < 3; c++) {
                  while(currIdx < maxSize && freq[currIdx] == 0) {
                      currIdx++;
                  }
  
                  freq[currIdx]--;
                  result[outerIdx][c] = currIdx;
              }
  
              if(result[outerIdx][2] - result[outerIdx][0] > k)
                  return {};
          }
  
          return result;
      }
  };