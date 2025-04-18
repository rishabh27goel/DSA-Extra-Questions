#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      string countAndSay(int n) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          if(n == 1)
              return "1";
  
          string previousSay = countAndSay(n - 1);
          int idx = 0;
  
          string currentSay = "";
          while(idx < previousSay.size()) {
              int charCount = 0;
              char ch = previousSay[idx];
  
              while(idx < previousSay.size() && previousSay[idx] == ch) {
                  charCount++;
                  idx++;
              }
  
              currentSay += to_string(charCount);
              currentSay.push_back(ch);
          }
          return currentSay; 
      }
  };