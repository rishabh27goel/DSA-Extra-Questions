#include <iostream>
using namespace std;

class Solution {
  public:
      // string makeFancyString(string str) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     // cout.tie(NULL);
  
      //     int size = str.size();
  
      //     string fancyStr = "";
      //     for(int currIdx = 0; currIdx < size; currIdx++) {
      //         if(!fancyStr.empty() && currIdx + 1 < size && fancyStr.back() == str[currIdx] && str[currIdx] == str[currIdx + 1]) 
      //             continue;
  
      //         fancyStr.push_back(str[currIdx]);
      //     }
      //     return fancyStr;
      // }
  
      string makeFancyString(string str) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = str.size();
  
          string fancyStr = "";
          int currIdx = 0;
  
          while(currIdx < size) {
              char ch = str[currIdx];
              int count = 0;
  
              while(currIdx < size && ch == str[currIdx]) {
                  count++, currIdx++;
              }
  
              count = min(count, 2);
              while(count > 0) {
                  fancyStr.push_back(ch);
                  count--;
              } 
          }
  
          return fancyStr;
      }
  };