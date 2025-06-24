#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int digits[100];
      bool isKBasePalindrome(long long number, int k) {
          int lastIdx = 0;
          while(number) {
              digits[lastIdx++] = (number % k);
              number /= k;
          }
  
          int leftIdx = 0;
          int rightIdx = lastIdx - 1;
  
          while(leftIdx <= rightIdx) {
              if(digits[leftIdx] != digits[rightIdx])
                  return false;
  
              leftIdx++;
              rightIdx--;
          }
          return true;
      }
  
      long long kMirror(int k, int n) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          long long totalSum = 0;
          int count = 0;
          int left = 1;
  
          while(count < n) {
              int right = left * 10;
              for(int op = 0; op < 2; op++) {
                  for(int idx = left; idx < right && count < n; idx++) {
                      long long number = idx;
                      int otherHalf = (op == 0 ? idx / 10 : idx);
  
                      while(otherHalf) {
                          number = (number * 10) + (otherHalf % 10);
                          otherHalf /= 10;
                      }
  
                      if(isKBasePalindrome(number, k)) {
                          totalSum += number;
                          count++;
                      }
                  }
              }
              left *= 10;
          }
  
          return totalSum;
      }
  };