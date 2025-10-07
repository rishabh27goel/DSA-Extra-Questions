#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> avoidFlood(vector<int>& rains) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = rains.size();
  
          unordered_map<int, int> lakeIdx;
          set<int> noRainIdx;
  
          vector<int> output(size, 1);
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(rains[currIdx] == 0)
                  noRainIdx.insert(currIdx);
  
              else {
                  // If Lake is already Filled
                  if(lakeIdx.count(rains[currIdx])) {
                      auto itr = noRainIdx.lower_bound(lakeIdx[rains[currIdx]]);
                      
                      // If we can't dry out the Lake
                      if(itr == noRainIdx.end())  return {};
  
                      output[*itr] = rains[currIdx];
                      noRainIdx.erase(itr);
                  }
  
                  output[currIdx] = -1;
                  lakeIdx[rains[currIdx]] = currIdx;
              }
          }
          return output;
      }
  };