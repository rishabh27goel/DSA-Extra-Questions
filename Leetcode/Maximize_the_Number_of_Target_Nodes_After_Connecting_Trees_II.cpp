#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      void fillTargetNodes(int totalNodes, vector<vector<int>> &adjList, int currNode, int parent, vector<vector<int>> &targetNodes) {
          targetNodes[currNode][0] = 0;
          targetNodes[currNode][1] = 1;
  
          for(auto &child : adjList[currNode]) {
              if(child == parent) continue;
  
              fillTargetNodes(totalNodes, adjList, child, currNode, targetNodes);
              targetNodes[currNode][0] += targetNodes[child][1];
              targetNodes[currNode][1] += targetNodes[child][0];
          }
      }
  
      void fillRemainingNodes(int totalNodes, vector<vector<int>> &adjList, int currNode, int parent, vector<vector<int>> &targetNodes) {
          if(parent != -1) {
              int oddCount = targetNodes[currNode][0] + (targetNodes[parent][1] - targetNodes[currNode][0]);
              int evenCount = targetNodes[currNode][1] + (targetNodes[parent][0] - targetNodes[currNode][1]);
  
              targetNodes[currNode][0] = oddCount;
              targetNodes[currNode][1] = evenCount;
          }
          
          for(auto &child : adjList[currNode]) {
              if(child == parent) continue;
  
              fillRemainingNodes(totalNodes, adjList, child, currNode, targetNodes);
          }
      }
  
      vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int sizeOne = edges1.size() + 1;
          int sizeTwo = edges2.size() + 1;
  
          vector<vector<int>> adjListOne(sizeOne);
          for(auto &edge : edges1) {
              adjListOne[edge[0]].push_back(edge[1]);
              adjListOne[edge[1]].push_back(edge[0]);
          }
  
          vector<vector<int>> adjListTwo(sizeTwo);
          for(auto &edge : edges2) {
              adjListTwo[edge[0]].push_back(edge[1]);
              adjListTwo[edge[1]].push_back(edge[0]);
          }
  
          vector<vector<int>> targetNodesTreeOne(sizeOne, vector<int> (2, 0));
          vector<vector<int>> targetNodesTreeTwo(sizeTwo, vector<int> (2, 0));
  
          fillTargetNodes(sizeOne, adjListOne, 0, -1, targetNodesTreeOne);
          fillTargetNodes(sizeTwo, adjListTwo, 0, -1, targetNodesTreeTwo);
  
          fillRemainingNodes(sizeOne, adjListOne, 0, -1, targetNodesTreeOne);
          fillRemainingNodes(sizeTwo, adjListTwo, 0, -1, targetNodesTreeTwo);
  
          int maxOddNodeTarget = 0;
          for(int node = 0; node < sizeTwo; node++) {
              maxOddNodeTarget = max(maxOddNodeTarget, targetNodesTreeTwo[node][0]);
          }
  
          vector<int> totalTargetNodes;
          for(int node = 0; node < sizeOne; node++) {
              totalTargetNodes.push_back(maxOddNodeTarget + targetNodesTreeOne[node][1]);
          }
  
          return totalTargetNodes;
      }
  };