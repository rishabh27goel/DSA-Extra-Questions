#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool isPossibleCandidate(int size, vector<int> &candies, long long k, int &candidateMax) {
          for(int &num : candies) {
              k -= (int) (num / candidateMax);
              if(k <= 0)    return true;
          }
          return false;
      }
  
      int maximumCandies(vector<int>& candies, long long k) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = candies.size();
  
          int maxCandies = 0;
          int leftMax = 1;
          int rightMax = 1e7;
  
          while(leftMax <= rightMax) {
              int middleMax = leftMax + (rightMax - leftMax) / 2;
              if(isPossibleCandidate(size, candies, k, middleMax)) {
                  maxCandies = middleMax;
                  leftMax = middleMax + 1;
              }
              else {
                  rightMax = middleMax - 1;
              }
          }
          return maxCandies;
      }
  };