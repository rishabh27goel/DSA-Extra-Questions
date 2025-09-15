#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int canBeTypedWords(string text, string letters) {
          int size = text.size();
  
          bool isBroken[26] = {0};
          for(int idx = 0; idx < letters.size(); idx++) {
              isBroken[letters[idx]-'a'] = true;
          }
  
          int currIdx = 0;
          int wordCount = 0;
  
          while(currIdx < size) {
              if(text[currIdx] == ' ') {
                  currIdx++;
              }
              else {
                  bool isValid = true;
                  while(currIdx < size && text[currIdx] != ' ') {
                      if(isBroken[text[currIdx]-'a']) {
                          isValid = false;
                      }
                      currIdx++;
                  }
                  if(isValid)    wordCount++;
              }
          }
          return wordCount;
      }
  };