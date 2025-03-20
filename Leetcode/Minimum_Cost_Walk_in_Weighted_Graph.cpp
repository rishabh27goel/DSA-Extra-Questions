#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // Here if we observe that AND is used and if we have multiple x, y, z numbers there AND is still (x & y & z)
      // All the edges in one component AND is the answer to the query
  
      int findParent(int node, vector<int> &parent) {
          if(parent[node] == node)
              return node;
  
          return parent[node] = findParent(parent[node], parent);
      }   
  
      vector<int> minimumCost(int totalNodes, vector<vector<int>>& edges, vector<vector<int>>& queries) {
          // ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          vector<int> rankValue(totalNodes);
          vector<int> parent(totalNodes);
  
          for(int node = 0; node < totalNodes; node++) {
              rankValue[node] = 0;
              parent[node] = node;
          }
  
          for(auto &edge : edges) {
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
  
              int p1 = findParent(u, parent);
              int p2 = findParent(v, parent);
  
              if(p1 != p2) {
                  if(rankValue[p1] >= rankValue[p2]) {
                      parent[p2] = p1;
                      rankValue[p1]++;
                  }   
                  else {
                      parent[p1] = p2;
                      rankValue[p2]++;
                  }
              }
          }
  
          vector<int> minCost(totalNodes, -1);
          for(auto &edge : edges) {
              int u = edge[0];
              int w = edge[2];
  
              int p = findParent(u, parent);
              if(minCost[p] == -1) {
                  minCost[p] = w;
              }
              else {
                  minCost[p] &= w;
              }
          }
  
          vector<int> answer;
          for(auto &query: queries) {
              int u = query[0];
              int v = query[1];
  
              int p1 = findParent(u, parent);
              int p2 = findParent(v, parent);
  
              if(u == v)
                  answer.push_back(0);
  
              else if(p1 == p2) 
                  answer.push_back(minCost[p1]);
              
              else 
                  answer.push_back(-1);
          }
          return answer;
      }
  };