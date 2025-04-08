#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minimumOperations(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          int freqCount[101] = {0};
          int leftIdx = 0;
          int currIdx = 0;
  
          int operations = 0;
          while(currIdx < size) {
              freqCount[nums[currIdx]]++;
              while(leftIdx < size && freqCount[nums[currIdx]] > 1) {
                  freqCount[nums[leftIdx]]--;
                  if(leftIdx + 1 < size)  freqCount[nums[leftIdx + 1]]--;
                  if(leftIdx + 2 < size)  freqCount[nums[leftIdx + 2]]--;
  
                  operations++;
                  leftIdx += 3;
              }
              currIdx++;
          }
  
          return operations;
      }
  };