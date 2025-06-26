#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long getSmallestCount(vector<int>& numsOne, vector<int>& numsTwo, long long candidate) {
          long long smallestCount = 0;
          for(int idx = 0; idx < numsOne.size(); idx++) {
              long long currVal = numsOne[idx];
  
              int left = 0;
              int right = numsTwo.size() - 1;
              
              while(left <= right) {
                  int mid = left + (right - left) / 2;
                  if(currVal >= 0 && (currVal * numsTwo[mid]) <= candidate) {
                      left = mid + 1;
                  }
                  else if(currVal < 0 && (currVal * numsTwo[mid]) > candidate) {
                      left = mid + 1;
                  }
                  else {
                      right = mid - 1;
                  }
              }
  
              if(currVal >= 0)
                  smallestCount += left;
              else 
                  smallestCount += (numsTwo.size() - left);
          }
          return smallestCount;
      }
  
      long long kthSmallestProduct(vector<int>& numsOne, vector<int>& numsTwo, long long k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int sizeOne = numsOne.size();
          int sizeTwo = numsTwo.size();
  
          long long left = -1e10;
          long long right = 1e10;
  
          while(left <= right) {
              long long candidate = left + (right - left) / 2;
              long long smallestCount = getSmallestCount(numsOne, numsTwo, candidate);
              if(smallestCount < k) {
                  left = candidate + 1;
              }
              else {
                  right = candidate - 1;
              }
          }
          return left;
      }
  };