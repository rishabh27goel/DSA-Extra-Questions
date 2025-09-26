#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // int getLowerBound(int size, vector<int> &nums, int currIdx, int target) {
      //     int startIdx = currIdx;
      //     int endIdx = size - 1;
  
      //     int outputIdx = -1;
      //     while(startIdx <= endIdx) {
      //         int middleIdx = startIdx + (endIdx - startIdx) / 2;
  
      //         if(nums[middleIdx] < target) {
      //             outputIdx = middleIdx;
      //             startIdx = middleIdx + 1;
      //         }
      //         else {
      //             endIdx = middleIdx - 1;
      //         }
      //     }
      //     return outputIdx;
      // }
  
      // int triangleNumber(vector<int>& nums) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     cout.tie(NULL);
  
      //     int size = nums.size();
  
      //     // Sort the array
      //     sort(nums.begin(), nums.end());
  
      //     int triangleCount = 0;
      //     for(int firstIdx = 0; firstIdx < size; firstIdx++) {
      //         for(int secondIdx = firstIdx + 1; secondIdx < size; secondIdx++) {
      //             int lowerIdx = getLowerBound(size, nums, secondIdx + 1, nums[firstIdx] + nums[secondIdx]);
      //             if(lowerIdx != -1)    triangleCount += (lowerIdx - secondIdx);
      //         }
      //     }
      //     return triangleCount;
      // }
  
      int triangleNumber(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
          if(size < 2)    return 0;
  
          // Sort the array
          sort(nums.begin(), nums.end());
  
          int triangleCount = 0;
          for(int currIdx = 2; currIdx < size; currIdx++) {
              int leftIdx = 0;
              int rightIdx = currIdx - 1;
  
              while(leftIdx <= rightIdx) {
                  if(nums[leftIdx] + nums[rightIdx] > nums[currIdx]) {
                      triangleCount += (rightIdx - leftIdx);
                      rightIdx--;
                  }
                  else {
                      leftIdx++;
                  }
              }
          }
          return triangleCount;
      }
  };