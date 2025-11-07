#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int findParent(int node, vector<int> &parent) {
          if(parent[node] == node)
              return node;
  
          return parent[node] = findParent(parent[node], parent);
      }
  
      vector<int> processQueries(int nodes, vector<vector<int>>& connections, vector<vector<int>>& queries) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
          
          vector<int> parent;
          for(int node = 0; node < nodes; node++) {
              parent.push_back(node);
          }
  
          for(int idx = 0; idx < connections.size(); idx++) {
              int p1 = findParent(connections[idx][0] - 1, parent);
              int p2 = findParent(connections[idx][1] - 1, parent);
              
              if(p1 <= p2)  parent[p2] = p1;
              else  parent[p1] = p2;
          }
  
          vector<queue<int>> gridMapping(nodes);
          for(int node = 0; node < nodes; node++) {
              int p = findParent(node, parent);
              gridMapping[p].push(node);
          }
  
          vector<int> activeNodes(nodes, true);
          vector<int> queryResult;
  
          for(int idx = 0; idx < queries.size(); idx++) {
              int type = queries[idx][0];
              int node = queries[idx][1] - 1;
              int p = findParent(node, parent);
  
              if(type == 1) {
                  if(activeNodes[node]) {
                      queryResult.push_back(node + 1);
                  }   
                  else {
                      queue<int> &currQ = gridMapping[p];
  
                      if(currQ.empty())  queryResult.push_back(-1);
                      else  queryResult.push_back(currQ.front() + 1);
                  }
              }   
              else {
                  queue<int> &currQ = gridMapping[p];
                  activeNodes[node] = false;
                  
                  while(!currQ.empty() && !activeNodes[currQ.front()]) {
                      currQ.pop();
                  }
              }
          }
          return queryResult;
      }
  };