#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      void fillCharArray(vector<int> &charCount, string &word) {
          for(int idx = 0; idx < word.size(); idx++) {
              charCount[word[idx]-'a']++;
          }
      }
  
      vector<string> removeAnagrams(vector<string>& words) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = words.size();
  
          vector<string> leftWords;
          int currIdx = 0;
  
          while(currIdx < size) {
              vector<int> parent(26, 0);
              fillCharArray(parent, words[currIdx]);
  
              int startIdx = currIdx;
              while(currIdx < size) {
                  vector<int> current(26, 0);
                  fillCharArray(current, words[currIdx]);
  
                  bool match = true;
                  for(int idx = 0; idx < 26; idx++) {
                      if(current[idx] != parent[idx]) {
                          match = false;
                          break;
                      }
                  }
  
                  if(match)  currIdx++;
                  else break;
              }
              leftWords.push_back(words[startIdx]);
          }
  
          return leftWords;
      }
  };