#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      long long minCost(vector<int>& basket1, vector<int>& basket2) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = basket1.size();
  
          int minCostFruit = INT_MAX;
          unordered_map<int, int> freqMap;
  
          for(int currIdx = 0; currIdx < size; currIdx++) {
              freqMap[basket1[currIdx]]++;
              freqMap[basket2[currIdx]]--;
              minCostFruit = min(minCostFruit, basket1[currIdx]);
              minCostFruit = min(minCostFruit, basket2[currIdx]);
          }
  
          vector<int> extraFruits;
          for(auto [key, count] : freqMap) {
              if(count % 2 != 0)
                  return -1;
  
              for(int c = 0; c < abs(count) / 2; c++) {
                  extraFruits.push_back(key);
              }
          }
          sort(extraFruits.begin(), extraFruits.end());
          
          long long totalCost = 0;
          for(int currIdx = 0; currIdx < extraFruits.size() / 2; currIdx++) {
              totalCost += min(2 * minCostFruit, extraFruits[currIdx]);
          }
  
          return totalCost;
      }
  };