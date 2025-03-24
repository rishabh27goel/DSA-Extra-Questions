#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countDays(int days, vector<vector<int>>& meetings) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = meetings.size();
          
          // Sort the meetings array
          sort(meetings.begin(), meetings.end(), [&](vector<int> &p1, vector<int> &p2) {
              if(p1[0] == p2[0])
                  return p1[1] < p2[1];
  
              return p1[0] < p2[0];
          });
  
          int start = meetings[0][0];
          int totalDays = start - 1;
          int end = meetings[0][1];
  
          for(int idx = 1; idx < size; idx++) {
              if(end >= meetings[idx][0]) {
                  start = min(start, meetings[idx][0]);
                  end = max(end, meetings[idx][1]);
              }
              else {
                  start = meetings[idx][0];
                  totalDays += max(start - end - 1, 0);
                  end = meetings[idx][1];
              }
          }
  
          totalDays += (days - end);
          return totalDays;
      }
  };