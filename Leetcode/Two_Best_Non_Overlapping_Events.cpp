#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maxTwoEvents(vector<vector<int>>& events) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = events.size();
  
          // Sort the events
          sort(events.begin(), events.end());
  
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
          int maxPrevValue = 0;
          int totalSum = 0;
  
          for(auto &event : events) {
              while(!minHeap.empty() && minHeap.top().first < event[0]) {
                  maxPrevValue = max(maxPrevValue, minHeap.top().second);
                  minHeap.pop();
              }
              totalSum = max(totalSum, maxPrevValue + event[2]);     
              minHeap.push(make_pair(event[1], event[2]));       
          }
          return totalSum;
      }
  };