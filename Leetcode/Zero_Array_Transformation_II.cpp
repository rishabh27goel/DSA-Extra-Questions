#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // Time :  O(q * n) -> 10^5 * 10^5
      // Space : O(n)
  
      // int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
      //     int size = nums.size();
  
      //     bool allZero = true;
      //     for(int opIdx = 0; opIdx < size; opIdx++) {
      //         if(nums[opIdx] != 0)
      //             allZero = false;
      //     }
      //     if(allZero)  return 0;
  
      //     vector<int> operationCount(size + 1, 0);
      //     for(int queryIdx = 0; queryIdx < queries.size(); queryIdx++) {
      //         int leftIdx = queries[queryIdx][0];
      //         int rightIdx = queries[queryIdx][1] + 1;
      //         int value = queries[queryIdx][2];
              
      //         operationCount[leftIdx] -= value;
      //         operationCount[rightIdx] += value;
  
      //         int totalReduction = 0;
      //         bool allZero = true;
  
      //         for(int opIdx = 0; opIdx < size; opIdx++) {
      //             totalReduction += operationCount[opIdx];
      //             if(nums[opIdx] + totalReduction > 0)
      //                 allZero = false;
      //         }
  
      //         if(allZero)  return queryIdx + 1;
      //     }
      //     return -1;
      // }
  
      // Time :  O(log(q) * (q + n))
      // Space : O(n)
  
      bool checkZeroArray(int size, vector<int> &nums, vector<vector<int>> &queries, int targetIdx) {
          vector<int> operationCount(size + 1);
          for(int queryIdx = 0; queryIdx <= targetIdx; queryIdx++) {
              int leftIdx = queries[queryIdx][0];
              int rightIdx = queries[queryIdx][1] + 1;
  
              operationCount[leftIdx] -= queries[queryIdx][2];
              operationCount[rightIdx] += queries[queryIdx][2];
          }
  
          int reductions = 0;
          for(int numIdx = 0; numIdx < size; numIdx++) {
              reductions += operationCount[numIdx];
              if(reductions + nums[numIdx] > 0)
                  return false;
          }
          return true;
      }
  
      int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          bool allZero = true;
          for(int numIdx = 0; numIdx < size; numIdx++) 
              if(nums[numIdx] != 0)
                  allZero = false;
  
          if(allZero) return 0;
  
          int leftIdx = 0;
          int rightIdx = queries.size() - 1;
  
          int candidateIdx = -2;
          while(leftIdx <= rightIdx) {
              int middleIdx = leftIdx + (rightIdx - leftIdx) / 2;
  
              if(checkZeroArray(size, nums, queries, middleIdx)) {
                  candidateIdx = middleIdx;
                  rightIdx = middleIdx - 1;
              }
              else {
                  leftIdx = middleIdx + 1;
              }
          }
          return candidateIdx + 1;
      }
  };