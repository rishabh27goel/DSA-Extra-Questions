#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // int minimumRecolors(string blocks, int k) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     // cout.tie(NULL);
  
      //     int size = blocks.size();
  
      //     int minOperations = size + 1;
      //     for(int currIdx = 0; currIdx <= size - k; currIdx++) {
      //         int whiteCount = 0;
      //         for(int windowIdx = currIdx; windowIdx < currIdx + k; windowIdx++) {
      //             if(blocks[windowIdx] == 'W')
      //                 whiteCount++;
      //         }
      //         minOperations = min(minOperations, whiteCount);
      //     }
      //     return minOperations;
      // }
  
      int minimumRecolors(string blocks, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = blocks.size();
  
          int whiteCount = 0;
          int windowSize = 0;
  
          int currIdx = 0;
          int startIdx = 0;
  
          int minOperations = size + 1;
          while(currIdx < size) {
              whiteCount += (blocks[currIdx] == 'W' ? 1 : 0);
              windowSize++;
  
              if(windowSize > k) {
                  whiteCount -= (blocks[startIdx] == 'W' ? 1 : 0);
                  windowSize--;
                  startIdx++;
              }
  
              if(windowSize == k) 
                  minOperations = min(minOperations, whiteCount);
  
              currIdx++;
          }
          return minOperations;
      }
  };