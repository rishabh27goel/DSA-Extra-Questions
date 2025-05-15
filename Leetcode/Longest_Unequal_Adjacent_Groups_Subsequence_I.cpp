#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
          int size = words.size();
  
          vector<string> sequence;
          int currBit = groups[0];
  
          for(int idx = 0; idx < size; idx++) {
              if(currBit == groups[idx]) {
                  sequence.push_back(words[idx]);
                  currBit = !currBit;
              }
          }
          
          return sequence;
      }
  };