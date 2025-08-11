#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int mod = 1e9 + 7;
      // vector<int> productQueries(int n, vector<vector<int>>& queries) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     cout.tie(NULL);
  
      //     vector<long> powers;
      //     long mul = 1;
  
      //     while(n > 0) {
      //         if(n & 1)   powers.push_back(mul);
      //         mul <<= 1;
      //         n >>= 1;
      //     }
  
      //     vector<int> output;
      //     for(auto &query : queries) {
      //         long product = 1;
      //         for(int idx = query[0]; idx <= query[1]; idx++) {
      //             product = (product % mod * powers[idx] % mod) % mod;
      //         }
      //         output.push_back(product);
      //     }
  
      //     return output;
      // }
  
      vector<int> productQueries(int n, vector<vector<int>>& queries) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          vector<long> powers;
          long mul = 1;
  
          while(n > 0) {
              if(n & 1)   powers.push_back(mul);
              mul <<= 1;
              n >>= 1;
          }
  
          int size = powers.size();
          vector<vector<int>> preprocess(size, vector<int> (size));
          vector<int> output;
  
          for(int startIdx = 0; startIdx < size; startIdx++) {
              long product = 1;
              for(int currIdx = startIdx; currIdx < size; currIdx++) {
                  product = (product % mod * powers[currIdx] % mod) % mod;
                  preprocess[startIdx][currIdx] = product;
              }
          }
          
          for(auto &query : queries)
              output.push_back(preprocess[query[0]][query[1]]);
      
  
          return output;
      }
  };