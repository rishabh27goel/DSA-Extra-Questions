#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int numRabbits(vector<int>& answers) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = answers.size();
  
          unordered_map<int, int> groupMap;
          int totalRabbits = 0;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              int currGroup = answers[currIdx] + 1;
              if(groupMap.find(currGroup) == groupMap.end()) {
                  totalRabbits += currGroup;
                  groupMap[currGroup] = currGroup;
              }
              if(--groupMap[currGroup] == 0) {
                  groupMap.erase(currGroup);
              }
          }
  
          return totalRabbits;
      }
  };