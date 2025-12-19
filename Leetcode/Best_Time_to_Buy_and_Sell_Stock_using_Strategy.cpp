#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {2
          int size = prices.size();
  
          vector<long long> storeSum(size);
          vector<long long> pricePrefixSum(size);
  
          long long prefixSum = 0;
          long long priceSum = 0;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              prefixSum += (prices[currIdx] * strategy[currIdx]);
              storeSum[currIdx] = prefixSum;
  
              priceSum += prices[currIdx];
              pricePrefixSum[currIdx] = priceSum;
          }
  
          long long profit = prefixSum;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              if(currIdx >= k - 1) {
                  long long rightSum = (prefixSum - storeSum[currIdx]);
                  long long leftSum = (currIdx - k >= 0 ? storeSum[currIdx - k] : 0);
                  long long lastK2Sum = (pricePrefixSum[currIdx] - pricePrefixSum[currIdx - (k / 2)]);
  
                  long long totalSum = leftSum + lastK2Sum + rightSum;
                  profit = max(profit, totalSum);
              }
          }
          return profit;
      }
  };