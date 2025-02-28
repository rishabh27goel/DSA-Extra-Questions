#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      string shortestCommonSupersequence(string strOne, string strTwo) {
          int strOneSize = strOne.size();
          int strTwoSize = strTwo.size();
  
          int dp[1001][1001];
          memset(dp, 0, sizeof(dp));
  
          for(int strOneIdx = 0; strOneIdx < strOneSize; strOneIdx++) {
              for(int strTwoIdx = 0; strTwoIdx < strTwoSize; strTwoIdx++) {
                  int longestSub = 0;
                  if(strOne[strOneIdx] == strTwo[strTwoIdx]) {
                      longestSub = max(longestSub, 1 + dp[strOneIdx][strTwoIdx]);
                  }
                  else {
                      longestSub = max(longestSub, max(dp[strOneIdx][strTwoIdx + 1], dp[strOneIdx + 1][strTwoIdx]));
                  }
  
                  dp[strOneIdx + 1][strTwoIdx + 1] = longestSub;
              }   
          }
  
          int strOneIdx = strOneSize;
          int strTwoIdx = strTwoSize;
  
          string supersequence = "";
          while(strOneIdx > 0 && strTwoIdx > 0) {
              if(strOne[strOneIdx - 1] == strTwo[strTwoIdx - 1]) {
                  supersequence.push_back(strOne[strOneIdx - 1]);
                  strOneIdx--;
                  strTwoIdx--;
              }
              else if(dp[strOneIdx][strTwoIdx - 1] >= dp[strOneIdx - 1][strTwoIdx]) {
                  supersequence.push_back(strTwo[strTwoIdx - 1]);
                  strTwoIdx--;
              }
              else {
                  supersequence.push_back(strOne[strOneIdx - 1]);
                  strOneIdx--;
              }
          }
  
          while(strOneIdx > 0) {
              supersequence.push_back(strOne[strOneIdx - 1]);
              strOneIdx--;
          }
  
          while(strTwoIdx > 0) {
              supersequence.push_back(strTwo[strTwoIdx - 1]);
              strTwoIdx--;
          }
  
          reverse(supersequence.begin(), supersequence.end());
          return supersequence;
      }   
  };