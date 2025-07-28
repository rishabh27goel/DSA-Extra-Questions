#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countHillValley(vector<int>& nums) {
          int size = nums.size();
  
          vector<int> prevNeighbour(size, -1);
          int prevNum = -1;
          int currIdx = 0;
  
          while(currIdx < size) {
              int currVal = nums[currIdx];
              while(currIdx < size && currVal == nums[currIdx]) {
                  prevNeighbour[currIdx] = prevNum;
                  currIdx++;
              }
              prevNum = currVal;
          }
  
          vector<int> nextNeighbour(size, -1);
          int nextNum = -1;
          currIdx = size - 1;
  
          while(currIdx >= 0) {
              int currVal = nums[currIdx];
              while(currIdx >= 0 && currVal == nums[currIdx]) {
                  nextNeighbour[currIdx] = nextNum;
                  currIdx--;
              }
              nextNum = currVal;
          }
  
          int hillValCount = 0;
          currIdx = 0;
  
          while(currIdx < size) {
              int startIdx = currIdx;
              int currVal = nums[currIdx];
  
              while(currIdx < size && currVal == nums[currIdx]) {
                  currIdx++;
              }
  
              if(prevNeighbour[startIdx] == -1 || nextNeighbour[startIdx] == -1)
                  continue;
  
              if(nums[startIdx] > prevNeighbour[startIdx] && nums[startIdx] > nextNeighbour[startIdx])
                  hillValCount++;
  
              else if(nums[startIdx] < prevNeighbour[startIdx] && nums[startIdx] < nextNeighbour[startIdx])
                  hillValCount++;
          }
          
          return hillValCount;
      }
  };