#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int numberOfBeams(vector<string>& bank) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = bank.size();
  
          int totalBeams = 0;
          int prevCount = 0;
          
          for(int currIdx = 0; currIdx < size; currIdx++) {
              int currCount = 0;
              for(int idx = 0; idx < bank[currIdx].size(); idx++) {
                  currCount += (bank[currIdx][idx] == '1');
              }
              if(currCount > 0) {
                  totalBeams += (prevCount * currCount);
                  prevCount = currCount;
              }
          }
          return totalBeams;
      }
  };