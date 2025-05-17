#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // int findDistance(vector<string>& words, int idx1, int idx2) {
      //     int differ = 0;
      //     for(int j = 0; j < words[idx1].size(); j++) {
      //         if(words[idx1][j] != words[idx2][j])
      //             differ++;
      //     }
      //     return differ;
      // }
  
      // vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
      //     int size = words.size();
  
      //     vector<int> chainCount(size, 1);
      //     vector<int> nextIdx(size, -1);
  
      //     int maxLen = 0;
      //     int startIdx = 0;
  
      //     for(int currIdx = 0; currIdx < size; currIdx++) {
      //         for(int innerIdx = currIdx - 1; innerIdx >= 0; innerIdx--) {
      //             if(groups[currIdx] != groups[innerIdx] && words[currIdx].size() == words[innerIdx].size() && findDistance(words, innerIdx, currIdx) == 1) {
      //                 if(chainCount[currIdx] < chainCount[innerIdx] + 1) {
      //                     chainCount[currIdx] = chainCount[innerIdx] + 1;
      //                     nextIdx[currIdx] = innerIdx;
      //                 }
                      
      //                 if(chainCount[currIdx] > maxLen) {
      //                     maxLen = chainCount[currIdx];
      //                     startIdx = currIdx;
      //                 }
      //             }
      //         }
      //     }
  
      //     vector<string> subsequence;
      //     while(startIdx != -1) { 
      //         subsequence.push_back(words[startIdx]);
      //         startIdx = nextIdx[startIdx];
      //     }
  
      //     reverse(subsequence.begin(), subsequence.end());
      //     return subsequence;
      // }
  
      int findDistance(vector<string>& words, int idx1, int idx2) {
          int differ = 0;
          for(int j = 0; j < words[idx1].size(); j++) {
              if(words[idx1][j] != words[idx2][j])
                  differ++;
          }
          return differ;
      }
  
      vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
          
          int size = words.size();
  
          vector<int> chainCount(size, 1);
          vector<int> nextIdx(size, -1);
  
          int maxLen = 0;
          int startIdx = 0;
  
          for(int currIdx = size - 1; currIdx >= 0; currIdx--) {
              for(int innerIdx = currIdx - 1; innerIdx >= 0; innerIdx--) {
                  if(groups[currIdx] != groups[innerIdx] && words[currIdx].size() == words[innerIdx].size() && findDistance(words, innerIdx, currIdx) == 1) {
                      if(chainCount[currIdx] + 1 > chainCount[innerIdx]) {
                          chainCount[innerIdx] = chainCount[currIdx] + 1;
                          nextIdx[innerIdx] = currIdx;
                      }
                      
                      if(chainCount[innerIdx] > maxLen) {
                          maxLen = chainCount[innerIdx];
                          startIdx = innerIdx;
                      }
                  }
              }
          }
  
          vector<string> subsequence;
          while(startIdx != -1) { 
              subsequence.push_back(words[startIdx]);
              startIdx = nextIdx[startIdx];
          }
          return subsequence;
      }
  };