#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool divideArray(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          int freqCount[501] = {0};
          for(int numIdx = 0; numIdx < size; numIdx++) {
              freqCount[nums[numIdx]]++;
          }
  
          for(int c = 0; c < 501; c++) {
              if(freqCount[c] == 0)   
                  continue;
  
              if(freqCount[c] & 1)    
                  return false;
          }
          return true;
      }
  };