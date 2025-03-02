#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<vector<int>> mergeArrays(vector<vector<int>>& numsOne, vector<vector<int>>& numsTwo) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int numOneSize = numsOne.size();
          int numTwoSize = numsTwo.size();
  
          int numsOneIdx = 0;
          int numsTwoIdx = 0;
  
          vector<vector<int>> mergedArr;
          while(numsOneIdx < numOneSize && numsTwoIdx < numTwoSize) {
              if(numsOne[numsOneIdx][0] == numsTwo[numsTwoIdx][0]) {
                  mergedArr.push_back({ numsOne[numsOneIdx][0], numsOne[numsOneIdx][1] + numsTwo[numsTwoIdx][1] });
                  numsOneIdx++;
                  numsTwoIdx++;
              }
              else if(numsOne[numsOneIdx][0] < numsTwo[numsTwoIdx][0]) {
                  mergedArr.push_back({ numsOne[numsOneIdx][0], numsOne[numsOneIdx][1] });
                  numsOneIdx++;
              }
              else {
                  mergedArr.push_back({ numsTwo[numsTwoIdx][0], numsTwo[numsTwoIdx][1] });
                  numsTwoIdx++;
              }
          }
  
          while(numsOneIdx < numOneSize && numsTwoIdx < numTwoSize) {
              if(numsOne[numsOneIdx][0] == numsTwo[numsTwoIdx][0]) {
                  mergedArr.push_back({ numsOne[numsOneIdx][0], numsOne[numsOneIdx][1] + numsTwo[numsTwoIdx][1] });
                  numsOneIdx++;
                  numsTwoIdx++;
              }
              else if(numsOne[numsOneIdx][0] < numsTwo[numsTwoIdx][0]) {
                  mergedArr.push_back({ numsOne[numsOneIdx][0], numsOne[numsOneIdx][1] });
                  numsOneIdx++;
              }
              else {
                  mergedArr.push_back({ numsTwo[numsTwoIdx][0], numsTwo[numsTwoIdx][1] });
                  numsTwoIdx++;
              }
          }
  
          while(numsOneIdx < numOneSize) {
              mergedArr.push_back({ numsOne[numsOneIdx][0], numsOne[numsOneIdx][1] });
              numsOneIdx++;
          }
  
          while(numsTwoIdx < numTwoSize) {
              mergedArr.push_back({ numsTwo[numsTwoIdx][0], numsTwo[numsTwoIdx][1] });
              numsTwoIdx++;
          }
  
          return mergedArr;
      }
  };