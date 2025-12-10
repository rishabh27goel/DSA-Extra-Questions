#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countPermutations(vector<int>& complexity) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = complexity.size();
          int mod = 1e9 + 7;
  
          for(int currIdx = 1; currIdx < size; currIdx++) {
              if(complexity[currIdx] <= complexity[0])
                  return 0;
          }
  
          long totalCount = 1;
          for(int num = 1; num < size; num++)
              totalCount = (totalCount * num) % mod;
          
          return totalCount;
      }
  };