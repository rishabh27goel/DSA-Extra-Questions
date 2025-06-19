#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int partitionArray(vector<int>& nums, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          // Sort the array
          sort(nums.begin(), nums.end());
  
          int partition = 0;
          int currIdx = 0;
  
          while(currIdx < size) {
              int startNum = nums[currIdx];
              while(currIdx < size && nums[currIdx] - startNum <= k) {
                  currIdx++;
              }
              partition++;
          }
  
          return partition;
      }
  };