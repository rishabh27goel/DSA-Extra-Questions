#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> pivotArray(vector<int>& nums, int pivot) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
  
          int pivotCount = 0;
          int leftIdx = 0;
  
          vector<int> largerNums;
          for(int idx = 0; idx < size; idx++) {
              if(nums[idx] == pivot) {
                  pivotCount++;
              }
              else if(nums[idx] < pivot) {  
                  swap(nums[idx], nums[leftIdx]);
                  leftIdx++;
              }
              else {
                  largerNums.push_back(nums[idx]);
              }
          }
  
          while(pivotCount > 0) {
              nums[leftIdx++] = pivot;
              pivotCount--;
          }
  
          for(int number : largerNums) {
              nums[leftIdx++] = number;
          }
  
          return nums;
      }
  };