#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = candies.size();
  
          vector<bool> boxOwned(size, false);
          vector<bool> canOpenBox(size, false);
          vector<bool> usedBox(size, false);
  
          for(int idx = 0; idx < size; idx++) {
              canOpenBox[idx] = (status[idx] == 1);
          }
  
          queue<int> boxQueue;
          int totalCandies = 0;
  
          for(int box : initialBoxes) {
              boxOwned[box] = true;
              if(canOpenBox[box]) {
                  boxQueue.push(box);
                  totalCandies += candies[box];
                  usedBox[box] = true;
              }
          }
  
          while(!boxQueue.empty()) {
              int currBox = boxQueue.front();
              boxQueue.pop();
  
              for(int box : keys[currBox]) {
                  canOpenBox[box] = true;
                  if(boxOwned[box] && !usedBox[box]) {
                      boxQueue.push(box);
                      totalCandies += candies[box];
                      usedBox[box] = true;
                  }
              }
  
              for(int box : containedBoxes[currBox]) {
                  boxOwned[box] = true;
                  if(canOpenBox[box] && !usedBox[box]) {
                      boxQueue.push(box);
                      totalCandies += candies[box];
                      usedBox[box] = true;
                  }
              }
          }
  
          return totalCandies;
      }
  };