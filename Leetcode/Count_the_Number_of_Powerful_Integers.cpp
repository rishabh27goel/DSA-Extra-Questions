#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      using ll = long long;
  
      ll dp[32];
      ll getPowerfulIntegers(string &rangeNum, string &suffix, int idx, bool tight, int limit) {
          if(rangeNum.size() < suffix.size())
              return 0;
  
          if(dp[16 * tight + idx] != -1)
              return dp[16 * tight + idx];
  
          int upperDigit = tight ? rangeNum[idx] - '0' : limit;
          // We have reached the prefix part of rangeNum
          if(idx == rangeNum.size() - suffix.size()) {
              if(!tight)  return dp[16 * tight + idx] = 1;
  
              string suffixRangeNum = rangeNum.substr(idx, (int) suffix.size());
              return dp[16 * tight + idx] = stoll(suffixRangeNum) >= stoll(suffix);
          }
          else {
              ll totalIntegers = 0;
              for(int dig = 0; dig <= min(limit, upperDigit); dig++) {
                  ll nextCall = getPowerfulIntegers(rangeNum, suffix, idx + 1, tight && (dig == upperDigit), limit);
                  totalIntegers += nextCall;
              }
              return dp[16 * tight + idx] = totalIntegers;
          }
      }
  
      ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          string left = to_string(start - 1);
          string right = to_string(finish);
  
          memset(dp, -1, sizeof(dp));
          ll rightNum = getPowerfulIntegers(right, s, 0, true, limit);
  
          memset(dp, -1, sizeof(dp));
          ll leftNum = getPowerfulIntegers(left, s, 0, true, limit);
      
          return max(0LL, rightNum - leftNum);
      }
  };