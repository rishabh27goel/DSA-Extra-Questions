#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long minSum(vector<int>& nums1, vector<int>& nums2) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int n1 = nums1.size();
          int n2 = nums2.size();
  
          long long sumOne = 0;
          long long sumTwo = 0;
  
          int zeroOne = 0;
          int zeroTwo = 0;
  
          for(int idx = 0; idx < n1; idx++)
              nums1[idx] == 0 ? zeroOne++ : sumOne += nums1[idx];
          
          for(int idx = 0; idx < n2; idx++)
              nums2[idx] == 0 ? zeroTwo++ : sumTwo += nums2[idx];
  
  
          if(zeroOne == 0 && zeroTwo == 0) 
              return sumOne == sumTwo ? sumOne : -1;
  
          if(zeroOne == 0) 
              return sumOne < sumTwo + zeroTwo ? -1 : sumOne;
  
          if(zeroTwo == 0) 
              return sumTwo < sumOne + zeroOne ? -1 : sumTwo;
  
          return max(sumOne + zeroOne, sumTwo + zeroTwo);
      }
  };