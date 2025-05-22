#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
  
          // Sort the queries by startTime
          sort(queries.begin(), queries.end(), [&](vector<int> &q1, vector<int> &q2) {
              return q1[0] < q2[0];
          });
  
          priority_queue<int> maxHeap;
          vector<int> rangeDelta(size + 1, 0);
  
          int operations = 0;
          int qryIdx = 0;
          
          for(int currIdx = 0; currIdx < size; currIdx++) {
              operations += rangeDelta[currIdx];
  
              while(qryIdx < queries.size() && queries[qryIdx][0] == currIdx) {
                  maxHeap.push(queries[qryIdx][1]);
                  qryIdx++;
              }
  
              while(operations < nums[currIdx] && !maxHeap.empty() && maxHeap.top() >= currIdx) {
                  operations++;
                  rangeDelta[maxHeap.top() + 1] -= 1;
                  maxHeap.pop();
              }
  
              if(operations < nums[currIdx])
                  return -1;
          }
  
          return maxHeap.size();
      }
  };