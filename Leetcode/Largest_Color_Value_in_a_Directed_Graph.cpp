#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int largestPathValue(string colors, vector<vector<int>>& edges) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = colors.size();
  
          vector<vector<int>> adjList(size);
          vector<int> degree(size, 0);
  
          for(auto &edge : edges) {
              degree[edge[1]]++;
              adjList[edge[0]].push_back(edge[1]);
          }
  
          queue<int> topoQueue;
          for(int node = 0; node < size; node++) {
              if(degree[node] == 0)
                  topoQueue.push(node);
          }
  
          int result = 0;
          int seenNodes = 0;
          vector<vector<int>> countNodes(size, vector<int> (26, 0));
  
          while(!topoQueue.empty()) {
              int topNode = topoQueue.front();
              topoQueue.pop();
              seenNodes++;
  
              result = max(result, ++countNodes[topNode][colors[topNode]-'a']);
              for(auto child : adjList[topNode]) {
                  for(int k = 0; k < 26; k++) {
                      countNodes[child][k] = max(countNodes[topNode][k], countNodes[child][k]);
                  }
  
                  degree[child]--;
                  if(degree[child] == 0)
                      topoQueue.push(child);
              }
          }
  
          return seenNodes != size ? -1 : result;
      }
  };