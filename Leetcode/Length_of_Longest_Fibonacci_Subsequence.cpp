#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // Points to Remember:
      // Each element is strictly increasing (each element is unique)
      // Each arr[i] is high we have to use the hash map
  
      // Brute Force
      // Time : O(n ^ 2 * log(K))
      // Space : O(n)
  
      // int lenLongestFibSubseq(vector<int>& arr) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     cout.tie(NULL);
  
      //     int arrSize = arr.size();
      
      //     unordered_set<long> elementsMap;
      //     for(int arrIdx = 0; arrIdx < arrSize; arrIdx++) {
      //         elementsMap.insert(arr[arrIdx]);
      //     }
  
      //     int longestSubsequence = 0;
      //     for(int prevIdx = 0; prevIdx < arrSize; prevIdx++) {
      //         for(int currIdx = prevIdx + 1; currIdx < arrSize; currIdx++) {
      //             long prevVal = arr[prevIdx];
      //             long currVal = arr[currIdx];
  
      //             long nextVal = prevVal + currVal;
      //             int currLength = 2; 
  
      //             while(elementsMap.find(nextVal) != elementsMap.end()) {
      //                 prevVal = currVal;
      //                 currVal = nextVal;
      //                 nextVal = prevVal + currVal;
      //                 currLength++;
      //             }
  
      //             if(currLength > 2)
      //                 longestSubsequence = max(longestSubsequence, currLength);
      //         }
      //     }
      //     return longestSubsequence;
      // }
  
      // Dp[i][j] -> Subsequence ending at i and j
      // Time : O(n ^ 2)
      // Space : O(n ^ 2)
  
      int lenLongestFibSubseq(vector<int>& arr) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          cout.tie(NULL);
  
          int arrSize = arr.size();
  
          unordered_map<long, int> elementToIdxMap;
          for(int arrIdx = 0; arrIdx < arrSize; arrIdx++) {
              elementToIdxMap[arr[arrIdx]] = arrIdx;
          }
  
          vector<vector<int>> dp(arrSize, vector<int> (arrSize, 2));
          int longestSubsequence = 0;
  
          for(int currIdx = 0; currIdx < arrSize; currIdx++) {
              for(int targetIdx = currIdx + 1; targetIdx < arrSize; targetIdx++) {
                  int prevVal = arr[targetIdx] - arr[currIdx];
                  
                  if(elementToIdxMap.find(prevVal) != elementToIdxMap.end()) {
                      int prevIdx = elementToIdxMap[prevVal];
                      if(prevIdx < currIdx) {
                          dp[currIdx][targetIdx] = max(dp[currIdx][targetIdx], 1 + dp[prevIdx][currIdx]);
                          longestSubsequence = max(dp[currIdx][targetIdx], longestSubsequence);
                      } 
                  }
              }
          }
          return longestSubsequence > 2 ? longestSubsequence : 0;
      }
  };