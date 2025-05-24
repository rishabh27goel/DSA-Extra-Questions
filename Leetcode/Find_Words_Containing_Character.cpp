#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> findWordsContaining(vector<string>& words, char x) {
          int size = words.size();
  
          vector<int> indexes;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              bool charFound = false;
              for(char &ch : words[currIdx]) {
                  if(ch == x) {
                      charFound = true;
                      break;
                  }
              }
              if(charFound)
                  indexes.push_back(currIdx);
          }
          return indexes;
      }
  };