#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool isVowel(char ch) {
          if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
              return true;
  
          if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
              return true;    
  
          return false;
      }
  
      bool isValid(string word) {
          int size = word.size();
          if(size < 3)
              return false;
  
          bool vowelPresent = false;
          bool consonantPresent = false;
  
          for(int idx = 0; idx < size; idx++) {
              if(word[idx] == '@' || word[idx] == '#' || word[idx] == '$')
                  return false;
  
              if((word[idx] >= 'a' && word[idx] <= 'z') || (word[idx] >= 'A' && word[idx] <= 'Z')) {
                  vowelPresent |= isVowel(word[idx]);
                  consonantPresent |= !isVowel(word[idx]);
              }
          }
          return consonantPresent && vowelPresent;
      }
  };