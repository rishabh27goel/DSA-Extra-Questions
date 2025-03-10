#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int getVowelIndex(char ch) {
          if(ch == 'a')   return 0;
          if(ch == 'e')   return 1;
          if(ch == 'i')   return 2;
          if(ch == 'o')   return 3;
          if(ch == 'u')   return 4;
          return -1;
      }
  
      // Time : O(n ^ 2)
      // Space : O(1)
  
      // long long countOfSubstrings(string word, int k) {
      //     int size = word.size();
  
      //     long long totalSubarrays = 0;
      //     for(int leftIdx = 0; leftIdx < size; leftIdx++) {
      //         int vowelCount = 0;
      //         int consonantCount = 0;
  
      //         vector<int> vowels(5, 0);
      //         for(int currIdx = leftIdx; currIdx < size; currIdx++) {
      //             int charIdx = getVowelIndex(word[currIdx]);
      //             if(charIdx == -1) {
      //                 consonantCount++;
      //             }
      //             else {
      //                 if(vowels[charIdx]++ == 0) {
      //                     vowelCount++;
      //                 }
      //             }
      //             if(consonantCount == k && vowelCount == 5) {
      //                 totalSubarrays++;
      //             }
      //         }
      //     }   
      //     return totalSubarrays;
      // }
  
      long long atLeastK(string word, int k) {
          int size = word.size();
  
          long long totalSubarrays = 0;
          int startIdx = 0;
          int currIdx = 0;
  
          vector<int> vowels(5, 0);
          int vowelCount = 0;
          int consonantCount = 0;
  
          while(currIdx < size) {
              int charIdx = getVowelIndex(word[currIdx]);
              if(charIdx == -1)
                  consonantCount++;
              else {
                  if(vowels[charIdx]++ == 0) 
                      vowelCount++;
              }   
  
              while(startIdx <= currIdx && vowelCount == 5 && consonantCount >= k) {
                  totalSubarrays += (size - currIdx);
  
                  int charIdx = getVowelIndex(word[startIdx]);
                  if(charIdx == -1)
                      consonantCount--;
                  else {
                      if(--vowels[charIdx] == 0) 
                          vowelCount--;
                  }  
                  startIdx++;
              }
              currIdx++;
          }
  
          return totalSubarrays;
      }
  
      long long countOfSubstrings(string word, int k) {
          return atLeastK(word, k) - atLeastK(word, k + 1);
      }
  };