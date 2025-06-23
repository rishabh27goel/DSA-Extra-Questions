#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<string> divideString(string str, int k, char fill) {
          int size = str.size();
  
          vector<string> groups;
          for(int idx = 0; idx < size; idx += k) {
              string sub = "";
              int moves = k;
              int currIdx = idx;
  
              while(currIdx < size && moves > 0) {
                  sub.push_back(str[currIdx]);
                  moves--, currIdx++;
              }
              while(moves > 0) {
                  sub.push_back(fill);
                  moves--;
              }
              groups.push_back(sub);
          }
          return groups;
      }
  };