#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> findXSum(vector<int>& nums, int k, int x) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          vector<int> xSumArray;
          int freqCount[51] = {0};
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              freqCount[nums[currIdx]]++;
              if(currIdx >= k)  freqCount[nums[currIdx - k]]--;
  
              priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
              for(int c = 0; c <= 50; c++) {
                  if(freqCount[c] == 0)   continue;
                  minHeap.push({freqCount[c], c});
                  if(minHeap.size() > x)  minHeap.pop();
              }
  
              int totalSum = 0;
              if(currIdx >= k - 1) {
                  while(!minHeap.empty()) {
                      auto pair = minHeap.top();
                      minHeap.pop();
                      totalSum += (pair.first * pair.second);
                  }
                  xSumArray.push_back(totalSum);
              }
          }
          return xSumArray;
      }
  };