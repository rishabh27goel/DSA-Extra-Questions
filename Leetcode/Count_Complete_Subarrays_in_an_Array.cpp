#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countCompleteSubarrays(vector<int>& nums) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = nums.size();
  
          int elementCount[2001];
          memset(elementCount, 0, sizeof(elementCount));
  
          int distinctElements = 0;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(elementCount[nums[currIdx]]++ == 0) 
                  distinctElements++;
          }
  
          int currentDistinct = 0;
          memset(elementCount, 0, sizeof(elementCount));
  
          int leftIdx = 0;
          int currIdx = 0;
  
          int nonValidSubarrays = 0;
          while(currIdx < size) {
              if(elementCount[nums[currIdx]]++ == 0) 
                  currentDistinct++;
  
              while(leftIdx <= currIdx && currentDistinct == distinctElements) {
                  if(--elementCount[nums[leftIdx]] == 0) 
                      currentDistinct--;
  
                  leftIdx++;
              }
  
              nonValidSubarrays += (currIdx - leftIdx + 1);
              currIdx++;
          }
  
          return ((size * (size + 1)) / 2) - nonValidSubarrays;
      }
  };