#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      string answerString(string word, int numFriends) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = word.size();
  
          int largestWindow = size - numFriends + 1;
          if(largestWindow == size)
              return word;
  
          string largestString = "";
          for(int currIdx = 0; currIdx <= size - largestWindow; currIdx++) {
              string currStr = word.substr(currIdx, largestWindow);
              if(largestString < currStr) {
                  largestString = currStr;
              }
          }
  
          for(int currIdx = size - largestWindow + 1; currIdx < size; currIdx++) {
              string currStr = word.substr(currIdx, size - currIdx);
              if(largestString < currStr) {
                  largestString = currStr;
              }
          }
          return largestString;
      }
  };