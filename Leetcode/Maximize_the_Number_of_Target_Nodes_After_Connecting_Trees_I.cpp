#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int getNeighbourNodes(int totalNodes, vector<vector<int>> &adjList, int start, int distance) {
          vector<bool> visited(totalNodes, false);
          visited[start] = true;
  
          queue<int> nodesQueue;
          nodesQueue.push(start);
  
          int count = 0;
          int neighbourNodes = 0;
  
          while(!nodesQueue.empty() && count <= distance) {
  
              int size = nodesQueue.size();
              while(size--) {
                  int node = nodesQueue.front();
                  nodesQueue.pop();
  
                  neighbourNodes++;
                  for(auto &child : adjList[node]) {
                      if(!visited[child]) {
                          nodesQueue.push(child);
                          visited[child] = true;
                      }
                  }
              }
  
              count++;
          }
  
          return neighbourNodes;
      }
  
      vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int sizeOne = edges1.size() + 1;
          int sizeTwo = edges2.size() + 1;
  
          vector<vector<int>> adjListOne(sizeOne);
          vector<vector<int>> adjListTwo(sizeTwo);
      
          for(auto &edge : edges1) {
              adjListOne[edge[0]].push_back(edge[1]);
              adjListOne[edge[1]].push_back(edge[0]);
          }
  
          for(auto &edge : edges2) {
              adjListTwo[edge[0]].push_back(edge[1]);
              adjListTwo[edge[1]].push_back(edge[0]);
          }
          
          int maxTreeTwoNode = 0;
          for(int node = 0; node < sizeTwo; node++) {
              int neighbourNodes = getNeighbourNodes(sizeTwo, adjListTwo, node, k - 1);
              maxTreeTwoNode = max(maxTreeTwoNode, neighbourNodes);
          }
  
          vector<int> targetNodes;
          for(int node = 0; node < sizeOne; node++) {
              int neighbourNodes = getNeighbourNodes(sizeOne, adjListOne, node, k);
              targetNodes.push_back(maxTreeTwoNode + neighbourNodes);
          }
          
          return targetNodes;
      }
  };