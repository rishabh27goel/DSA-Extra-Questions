#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int getParent(int node, vector<int> &parent) {
          if(parent[node] == node)
              return node;
  
          return parent[node] = getParent(parent[node], parent);
      }
  
      int countCompleteComponents(int totalNodes, vector<vector<int>>& edges) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          // cout.tie(NULL);
  
          vector<int> parent(totalNodes);
          vector<int> rankValue(totalNodes);
  
          for(int node = 0; node < totalNodes; node++) {
              parent[node] = node;
              rankValue[node] = 0;
          }
  
          for(auto &edge : edges) {
              int u = edge[0];
              int v = edge[1];
  
              int p1 = getParent(u, parent);
              int p2 = getParent(v, parent);
          
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
  
          unordered_map<int, pair<int, int>> componentInfo;
          for(int node = 0; node < totalNodes; node++) {
              int p = getParent(node, parent);
  
              if(componentInfo.find(p) == componentInfo.end())
                  componentInfo[p] = make_pair(1, 0);
              else 
                  componentInfo[p].first++;        
          }
  
          for(auto &edge : edges) {
              int p = getParent(edge[0], parent);
              componentInfo[p].second++;  
          }
  
          int components = 0;
          for(auto itr : componentInfo) {
              int vertices = itr.second.first;
              int edgesCount = itr.second.second;
  
              int target = (vertices * (vertices - 1)) / 2;
              if(target == edgesCount) {
                  components++;
              }
          }
          return components;
      }
  };