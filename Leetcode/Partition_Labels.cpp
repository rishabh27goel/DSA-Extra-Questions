#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // Time : O(n)
      // Space : O(26)
  
      vector<int> partitionLabels(string str) {
          int size = str.size();
  
          vector<int> lastIdx(26, -1);
          for(int idx = 0; idx < size; idx++) {
              lastIdx[str[idx]-'a'] = idx;
          }
  
          vector<int> partitionLength;
          int currIdx = 0;
  
          while(currIdx < size) {
              int maxReach = currIdx;
              int subLength = 0;
  
              while(currIdx < size && currIdx <= maxReach) {
                  maxReach = max(maxReach, lastIdx[str[currIdx]-'a']);
                  subLength++, currIdx++;
              }
  
              partitionLength.push_back(subLength);
          }
  
          return partitionLength;
      }
  };