#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int minOperations(vector<int>& nums, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
  
          bool exists[101] = {0};
          int operations = 0;
          int minNum = INT_MAX;
  
          for(int idx = 0; idx < size; idx++) {
              if(!exists[nums[idx]]) {
                  exists[nums[idx]] = true;
                  operations++;
              }        
              minNum = min(minNum, nums[idx]);
          }
  
          if(minNum > k)   
              return operations;
  
          if(minNum == k)  
              return operations - 1;
      
          return -1;
      }   
  };