#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int maxEvents(vector<vector<int>>& events) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          cout.tie(NULL);
  
          int size = events.size();
  
          // Sort the array
          sort(events.begin(), events.end());
  
          int maxLimit = 0;
          for(int idx = 0; idx < size; idx++) {
              maxLimit = max(maxLimit, events[idx][1]);
          }
  
          priority_queue<int, vector<int>, greater<int>> minHeap;
          int totalEvents = 0;
          int currIdx = 0;
  
          for(int limit = 1; limit <= maxLimit; limit++) {
              while(currIdx < size && events[currIdx][0] <= limit) {
                  minHeap.push(events[currIdx][1]);
                  currIdx++;
              }
  
              // Remove the expired events
              while(!minHeap.empty() && minHeap.top() < limit) {
                  minHeap.pop();
              }
  
              if(!minHeap.empty()) {
                  minHeap.pop();
                  totalEvents++;
              }
          }
  
          return totalEvents;
      }
  };