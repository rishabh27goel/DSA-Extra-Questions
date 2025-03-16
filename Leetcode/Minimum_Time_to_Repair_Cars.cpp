#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool isTimeTakenPossible(int size, vector<int> &ranks, int count, long long currentCap) {
          long long cars = count;
          for(int idx = 0; idx < size; idx++) {
              double currentTime = (currentCap / ranks[idx]);
              cars -= (long long) sqrt(currentTime);
  
              if(cars <= 0)   return true;
          }
          return false;
      }
  
      long long repairCars(vector<int>& ranks, int cars) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = ranks.size();
  
          long long leftCap = 1;
          long long rightCap = LLONG_MAX;
  
          long long candidate = 0;
          while(leftCap <= rightCap) {
              long long middleCap = leftCap + (rightCap - leftCap) / 2;
              if(isTimeTakenPossible(size, ranks, cars, middleCap)) {
                  candidate = middleCap;
                  rightCap = middleCap - 1;
              }
              else {
                  leftCap = middleCap + 1;
              }
          }
          return candidate;
      }
  };