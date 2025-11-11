#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minOperations(vector<int>& nums) {  
          int size = nums.size();
  
          int segments = 0;
          vector<int> st;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              // End of all segments till now
              while(!st.empty() && st.back() > nums[currIdx]) {
                  st.pop_back();
              }
              
              // We dont want to count segments when the element is Zero
              if(nums[currIdx] == 0)  continue;
  
              // New segments started
              if(st.empty() || st.back() < nums[currIdx]) {
                  segments++;
                  st.push_back(nums[currIdx]);
              }
          }
          return segments;
      }
  };