#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      string clearStars(string str) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = str.size();
  
          vector<vector<int>> charIdx(26);
          vector<bool> removed(size, false);
  
          for(int idx = 0; idx < size; idx++) {
              if(str[idx] == '*') {
                  for(int c = 0; c < 26; c++) {
                      if(charIdx[c].empty())
                          continue;
  
                      int lastIdx = charIdx[c].back();
                      removed[lastIdx] = true;
                      charIdx[c].pop_back();
                      break;
                  }
              }   
              else {
                  charIdx[str[idx]-'a'].push_back(idx);
              }
          }
  
          string smallestStr = "";
          for(int idx = 0; idx < size; idx++) {
              if(removed[idx] || str[idx] == '*')        
                  continue;
  
              smallestStr.push_back(str[idx]);
          }
  
          return smallestStr;
      }
  };