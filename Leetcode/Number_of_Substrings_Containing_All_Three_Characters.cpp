#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // int numberOfSubstrings(string str) {
      //     int size = str.size();
  
      //     int totalSubarrays = 0;
      //     for(int startIdx = 0; startIdx < size; startIdx++) {
      //         vector<int> charCount(3, 0);
      //         int totalChars = 0;
  
      //         for(int currIdx = startIdx; currIdx < size; currIdx++) {
      //             if(charCount[str[currIdx]-'a']++ == 0)
      //                 totalChars++;
                  
      //             if(totalChars == 3) 
      //                 totalSubarrays++;
      //         }
      //     }
      //     return totalSubarrays;
      // }
  
      int numberOfSubstrings(string str) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = str.size();
  
          int startIdx = 0;
          int currIdx = 0;
  
          vector<int> charCount(3, 0);
          int chars = 0;
  
          int totalSubarrays = 0;
          while(currIdx < size) {
              if(charCount[str[currIdx]-'a']++ == 0)
                  chars++;
  
              while(startIdx <= currIdx && chars == 3) {
                  // Add all possible subarrays
                  totalSubarrays += (size - currIdx);
  
                  if(--charCount[str[startIdx]-'a'] == 0)
                      chars--;
  
                  startIdx++;
              }
  
              currIdx++;
          }
          return totalSubarrays;
      }
  };