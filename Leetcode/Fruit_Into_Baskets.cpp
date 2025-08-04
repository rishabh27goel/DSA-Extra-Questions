#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int totalFruit(vector<int>& fruits) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = fruits.size();
  
          int freqMap[100001] = {0};
          int mapSize = 0;
  
          int startIdx = 0;
          int endIdx = 0;
  
          int maxLength = 0;
          while(endIdx < size) {
              if(freqMap[fruits[endIdx]]++ == 0)
                  mapSize++;
              
              while(startIdx <= endIdx && mapSize > 2) {
                  if(--freqMap[fruits[startIdx]] == 0)
                      mapSize--;
                              
                  startIdx++;
              }
  
              maxLength = max(maxLength, endIdx - startIdx + 1);
              endIdx++;
          }
          return maxLength;
      }
  };