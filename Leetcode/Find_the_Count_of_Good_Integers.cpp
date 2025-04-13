#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
      using ll = long long;
      ll totalGoodIntegers = 0;
  
      vector<ll> factorial;
      unordered_set<string> numberSet;
  
      void fillFactorial() {
          factorial.resize(11, 1);
          ll fact = 1;
  
          for(int curr = 2; curr <= 10; curr++) {
              fact *= curr;
              factorial[curr] = fact;
          }
      }
  
      bool isKPalindromic(string &palindromeStr, int k) {
          return stoll(palindromeStr) % k == 0;
      }
  
      // Pass by value here 
      ll getAllWays(int size, string palindromeStr) {
          sort(palindromeStr.begin(), palindromeStr.end());
          
          if(numberSet.find(palindromeStr) != numberSet.end())  return 0;
          numberSet.insert(palindromeStr);
  
          ll totalWays = factorial[size];
  
          int digitCount[10] = {0};
          for(char &ch : palindromeStr) {
              digitCount[ch-'0']++;
          }
  
          for(int dig = 0; dig < 10; dig++) {
              totalWays /= factorial[digitCount[dig]];
          }
  
          if(digitCount[0] > 0) {
              digitCount[0]--;
              ll invalidWays = factorial[size - 1];
              for (int dig = 0; dig < 10; dig++) {
                  invalidWays /= factorial[digitCount[dig]];
              }
              totalWays -= invalidWays;
          }
  
          return totalWays;
      }
  
      void generatePalindrome(int n, int k, string &palindromeStr, int idx) {
          if(idx == (n + 1) / 2) {
              if(isKPalindromic(palindromeStr, k)) {
                  totalGoodIntegers += getAllWays(n, palindromeStr);
              }
              return;
          }
  
          char startChar = (idx == 0 ? '1' : '0');
          for(; startChar <= '9'; startChar++) {
              palindromeStr[idx] = startChar;
              palindromeStr[n - idx - 1] = startChar;
              
              generatePalindrome(n, k, palindromeStr, idx + 1);
          }
      }
  
      ll countGoodIntegers(int n, int k) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          // Pre-compute factorial
          fillFactorial();
          numberSet.clear();
          totalGoodIntegers = 0;
      
          // Generate all possible 
          string palindromeStr(n, '0');
          generatePalindrome(n, k, palindromeStr, 0);
  
          return totalGoodIntegers;
      }
  };