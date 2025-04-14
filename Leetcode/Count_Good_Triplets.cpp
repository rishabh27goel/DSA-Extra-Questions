#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = arr.size();
  
          int goodTriplets = 0;
          for(int outerIdx = 0; outerIdx < size; outerIdx++) {
              for(int middleIdx = outerIdx + 1; middleIdx < size; middleIdx++) {
                  for(int innerIdx = middleIdx + 1; innerIdx < size; innerIdx++) {
                      if(abs(arr[outerIdx] - arr[middleIdx]) <= a && abs(arr[middleIdx] - arr[innerIdx]) <= b && abs(arr[innerIdx] - arr[outerIdx]) <= c) {
                          goodTriplets++;
                      }
                  }
              }
          }
          return goodTriplets;
      }
  };