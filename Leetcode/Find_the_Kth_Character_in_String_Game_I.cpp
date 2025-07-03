#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      char kthCharacter(int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          string str = "a";
          while(str.size() < k) {
              string nextStr = "";
              for(int idx = 0; idx < str.size(); idx++) {
                  char nextChar = (((str[idx]-'a') + 1) % 26) + 'a';
                  nextStr.push_back(nextChar);
              }
              str += nextStr;
          }
          return str[k-1];
      }
  };