#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int playerSize = players.size();
          int trainerSize = trainers.size();
  
          sort(players.begin(), players.end());
          sort(trainers.begin(), trainers.end());
  
          int pIdx = 0;
          int tIdx = 0;
  
          while(tIdx < trainerSize && pIdx < playerSize) {
              if(players[pIdx] <= trainers[tIdx]) {
                  pIdx++;
              }
              
              tIdx++;
          }
  
          return pIdx;
      }
  };