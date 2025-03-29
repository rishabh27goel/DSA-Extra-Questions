#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
      /*
          1. nums -> n positive integer (nums[i] >= 1) and k
      
          2. Start score = 1 
          3. Choose new subarray [l ... r] && len > 0
          4. Choose x - highest prime score
              score *= x
          
      */
  
      /*
          nums = [8, 3, 9, 3, 8]
                  1, 1, 2, 1, 1
  
          nums = [19, 12, 14, 6, 10, 18]
                 1 2 2 2 2 2
  
          right ->   1 5 4 3 2 1
      */
  
      unordered_map<int, int> powerMap;
      void fillPowerMap(vector<int> &nums) {
          for(int val : nums) {
              int factorCount = 0;
              int currVal = val;
  
              for(int factor = 2; factor * factor <= currVal; factor++) {
                  if(currVal % factor == 0) {
                      factorCount++;
                      while(currVal % factor == 0) {
                          currVal /= factor;
                      }
                  }
              }
  
              if(currVal > 1)    factorCount++;
              powerMap[val] = factorCount;
          }
      }
      
      void fillLeftRightIdx(vector<int> &nums, vector<int> &leftIdx, vector<int> &rightIdx) {
          stack<int> monoStack;
          for (int index = 0; index < nums.size(); index++) {
              while (!monoStack.empty() && powerMap[nums[monoStack.top()]] < powerMap[nums[index]]) {
                  int topIndex = monoStack.top();
                  monoStack.pop();
                  rightIdx[topIndex] = index;
              }
  
              if (!monoStack.empty())
                  leftIdx[index] = monoStack.top();
  
              monoStack.push(index);
          }
      }
  
      long long powerWithMod(long long number, long long power, long long mod) {
          long long result = 1;
          while(power > 0) {
              if(power & 1) 
                  result = (result * number) % mod;
  
              number = (number * number) % mod;
              power >>= 1;
          }
          return result % mod;
      }
  
      int maximumScore(vector<int>& nums, long k) {
          int mod = 1e9 + 7;
  
          int size = nums.size();
  
          // Fill the power map
          fillPowerMap(nums);    
  
          // Sort the nums array
          vector<pair<int, int>> sortedNums;
          for(int idx = 0; idx < size; idx++) 
              sortedNums.push_back(make_pair(nums[idx], idx));
  
          sort(sortedNums.begin(), sortedNums.end(), greater<pair<int, int>> ());
          
          // Fill the left and right indexes vector to track the valid power subarrays
          vector<int> leftIdx(size, -1);
          vector<int> rightIdx(size, size);
  
          fillLeftRightIdx(nums, leftIdx, rightIdx);
  
          // Find the maximum score
          long long maxScore = 1;
          for(int idx = 0; idx < size && k > 0; idx++) {
              long long currVal = sortedNums[idx].first;
              int actualIdx = sortedNums[idx].second;
  
              long long leftCount = actualIdx - leftIdx[actualIdx];
              long long rightCount = rightIdx[actualIdx] - actualIdx;
  
              // This is important and easy to miss we are counting 
              //  the ways of subarray which has current element 
              long long subCount = leftCount * rightCount;
  
              long long currCount = min((long long) k, subCount);
              k -= currCount;
  
              long long modValue = powerWithMod(currVal, currCount, mod);
              maxScore = (maxScore * modValue) % mod;
          }
          return maxScore;
      }
  
      void getLeftmostValidSubarray(vector<int> &nums, vector<int> &leftIdx) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          int size = nums.size();
  
          stack<int> monoStack;
          for(int idx = 0; idx < size; idx++) {
              while(!monoStack.empty() && powerMap[nums[monoStack.top()]] >= powerMap[nums[idx]])
                  monoStack.pop();
      
              if(!monoStack.empty()) 
                  leftIdx[idx] = monoStack.top();
      
              monoStack.push(idx);
          }
      }
      void getRightmostValidSubarray(vector<int> &nums, vector<int> &rightIdx) {
          int size = nums.size();
  
          stack<int> monoStack;
          for(int idx = size - 1; idx >= 0; idx--) {
              while(!monoStack.empty() && powerMap[nums[monoStack.top()]] < powerMap[nums[idx]])
                  monoStack.pop();
      
              if(!monoStack.empty()) 
                  rightIdx[idx] = monoStack.top();
      
              monoStack.push(idx);
          }
      }
  };