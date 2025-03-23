#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int countPaths(int n, vector<vector<int>>& roads) {
          // ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int mod = 1e9 + 7;
  
          vector<vector<pair<int, int>>> adjList(n);
          for(auto edge : roads) {
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
  
              adjList[u].push_back(make_pair(v, w));
              adjList[v].push_back(make_pair(u, w));
          }
  
          vector<long> trackTime(n, LONG_MAX);
          trackTime[0] = 0;
  
          vector<long> countWays(n, 0);
          countWays[0] = 1;
  
          priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> minTime;
          minTime.push({0, 0});
  
          while(!minTime.empty()) {
              auto currInfo = minTime.top();
              minTime.pop();
  
              long currTime = currInfo.first;
              int node = currInfo.second;
  
              for(auto child : adjList[node]) {
                  if(trackTime[child.first] > currTime + child.second) {
                      trackTime[child.first] = currTime + child.second;
                      minTime.push(make_pair(trackTime[child.first], child.first));
                      countWays[child.first] = countWays[node];
                  }
                  else if(trackTime[child.first] == currTime + child.second) {
                      countWays[child.first] = (countWays[child.first] + countWays[node]) % mod;
                  }
              }
          }
  
          return countWays[n-1];
      }
  };