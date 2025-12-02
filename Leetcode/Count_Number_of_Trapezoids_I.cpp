#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countTrapezoids(vector<vector<int>>& points) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = points.size();
          int mod = 1e9 + 7;
  
          unordered_map<int, int> pointsCount;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              pointsCount[points[currIdx][1]]++;
          }
  
          long totalCount = 0;
          long prefixCount = 0;
  
          for(auto [key, count]: pointsCount) {
              if(count < 2)   continue;
  
              long totalPairs = (1L * count * (count - 1)) / 2;
              totalCount = (totalCount + (prefixCount % mod * totalPairs % mod)) % mod;
              prefixCount = (prefixCount + totalPairs) % mod;
          }
          return totalCount;
      }
  };