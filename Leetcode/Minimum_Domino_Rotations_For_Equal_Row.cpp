#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int getMinimumCandidates(int size, vector<int> &tops, vector<int> &bottoms, int target) {
          int topFlips = 0;
          int bottomFlips = 0;
          
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(bottoms[currIdx] != target && tops[currIdx] != target)
                  return -1;
  
              if(tops[currIdx] != target)
                  topFlips++;
  
              if(bottoms[currIdx] != target)
                  bottomFlips++;       
          }
          return min(topFlips, bottomFlips);
      }
  
      int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = tops.size();
  
          int minOps = INT_MAX;
          int topOps = getMinimumCandidates(size, tops, bottoms, tops[0]);
          if(topOps != -1)
              minOps = min(minOps, topOps);
  
          int bottomOps = getMinimumCandidates(size, tops, bottoms, bottoms[0]);
          if(bottomOps != -1)
              minOps = min(minOps, bottomOps);
  
          return minOps == INT_MAX ? -1 : minOps;
      }
  };