#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // Here, I thought of dynamic programming at first but the constraints 
      // don't allow us to have O(n ^ 2) Solution
  
      // Here if we observe that when we do k partition on [a1, a2, a3, ...., a4]
      // We have k - 1 pair of adjacent points in the array which will be start 
      // and end to different splits (These splits are contributing to the final sum)
  
      // long long putMarbles(vector<int>& weights, int k) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     cout.tie(NULL);
  
      //     int size = weights.size();
  
      //     priority_queue<long long, vector<long long>, greater<long long>> minHeap;
      //     priority_queue<long long> maxHeap;
  
      //     for(int idx = 1; idx < size; idx++) {
      //         long long sum = (long long) weights[idx - 1] + (long long) weights[idx];
      //         minHeap.push(sum);
      //         maxHeap.push(sum);
  
      //         if(minHeap.size() > k - 1)  minHeap.pop();
      //         if(maxHeap.size() > k - 1)  maxHeap.pop();
      //     }
  
      //     long long maxSum = 0;
      //     while(!minHeap.empty()) {
      //         maxSum += minHeap.top();
      //         minHeap.pop();
      //     }
  
      //     long long minSum = 0;
      //     while(!maxHeap.empty()) {
      //         minSum += maxHeap.top();
      //         maxHeap.pop();
      //     }
  
      //     return maxSum - minSum;
      // }
  
      long long putMarbles(vector<int>& weights, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = weights.size();
  
          vector<long long> pairs;
          for(int idx = 1; idx < size; idx++) {
              long long sum = (long long) weights[idx - 1] + (long long) weights[idx];
              pairs.push_back(sum);
          }
          sort(pairs.begin(), pairs.end());
  
          long long maxSum = 0;
          long long minSum = 0;
  
          int count = 0;
          int leftIdx = 0;
          int rightIdx = pairs.size() - 1;
      
          while(leftIdx < pairs.size() && rightIdx >= 0 && count < k - 1) {
              minSum += (long long) pairs[leftIdx];
              maxSum += (long long) pairs[rightIdx];
              count++;
              leftIdx++, rightIdx--;
          }
  
          return maxSum - minSum;
      }
  };