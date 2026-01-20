#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> minBitwiseArray(vector<int>& nums) {
          int size = nums.size();
  
          int validMatch[1000];
          memset(validMatch, -1, sizeof(validMatch));
  
          for(int start = 1; start <= 1000; start++) {
              int xorVal = (start | (start + 1));
              if(xorVal <= 1000 && validMatch[xorVal] == -1)
                  validMatch[xorVal] = start;
          }
  
          vector<int> answer;
          for(int currIdx = 0; currIdx < size; currIdx++) 
              answer.push_back(validMatch[nums[currIdx]]);
          
          return answer;
      }
  };