#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int numOfSubarrays(vector<int>& arr) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int mod = 1e9 + 7;
          int arrSize = arr.size();
  
          long totalSubarrays = 0;
          int prefixSum = 0;
  
          int evenCount = 0;
          int oddCount = 0;
  
          for(int idx = 0; idx < arrSize; idx++) {
              prefixSum += arr[idx];
              if(prefixSum & 1)   
                  totalSubarrays++;
  
              if(prefixSum & 1) {
                  totalSubarrays = (totalSubarrays + evenCount) % mod;
                  oddCount++;
              }
              else {
                  totalSubarrays = (totalSubarrays + oddCount) % mod;
                  evenCount++;
              }
          }
  
          return totalSubarrays % mod;
      }
  };