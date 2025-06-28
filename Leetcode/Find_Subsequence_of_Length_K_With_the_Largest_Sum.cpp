#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      vector<int> maxSubsequence(vector<int>& nums, int k) {
          int size = nums.size();
  
          priority_queue<int, vector<int>, greater<int>> minHeap;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              minHeap.push(nums[currIdx]);
              if(minHeap.size() > k)  minHeap.pop();
          }
      
          vector<int> sequence;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              int topNum = INT_MAX;
              if(!minHeap.empty()) {
                  topNum = minHeap.top();
              }
              
              if(nums[currIdx] > topNum) {
                  sequence.push_back(nums[currIdx]);
              }
              else if(nums[currIdx] == topNum) {
                  sequence.push_back(nums[currIdx]);
                  minHeap.pop();
              }
          }
          return sequence;
      }
  };