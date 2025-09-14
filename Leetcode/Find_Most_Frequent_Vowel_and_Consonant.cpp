#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool isVowel(char ch) {
          if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
              return true;
  
          return false;
      }
  
      int maxFreqSum(string str) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = str.size();
  
          int maxVowel = 0;
          int maxConsonant = 0;
          int charCount[26] = {0};
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(isVowel(str[currIdx]))
                  maxVowel = max(maxVowel, ++charCount[str[currIdx]-'a']);
              else
                  maxConsonant = max(maxConsonant, ++charCount[str[currIdx]-'a']);
          }
          return maxVowel + maxConsonant;
      }
  };