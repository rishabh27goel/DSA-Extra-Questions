#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
      int maximumPathSum = INT_MIN;
      void getMaximumSumToLeaf(vector<vector<int>> &adjList, vector<int>& amount, vector<int> &bobVisitedTime, int source, int parent, int pathSum, int currTime) {
          int currSum = amount[source];
          if(bobVisitedTime[source] == currTime) {
              currSum = (amount[source] / 2);
          }
          else if(bobVisitedTime[source] != -1 && bobVisitedTime[source] < currTime) {
              currSum = 0;
          }
  
          int totalChild = 0;
          for(auto &child : adjList[source]) {
              if(child == parent)  continue;
  
              getMaximumSumToLeaf(adjList, amount, bobVisitedTime, child, source, pathSum + currSum, currTime + 1);
              totalChild++;
          }
  
          // Leaf Nodes
          if(totalChild == 0) {
              maximumPathSum = max(maximumPathSum, pathSum + currSum);
          }
      }
  
      int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int totalNodes = edges.size() + 1;
  
          vector<vector<int>> adjList(totalNodes);
          for(auto &edge : edges) {
              int u = edge[0];
              int v = edge[1];
  
              adjList[u].push_back(v);
              adjList[v].push_back(u);
          }
  
          vector<int> bobVisitedTime(totalNodes, -1);
          fillPathToRoot(adjList, bobVisitedTime, bob, 0, -1, 1);
  
          getMaximumSumToLeaf(adjList, amount, bobVisitedTime, 0, -1, 0, 1);
          return maximumPathSum;
      }
  
      bool fillPathToRoot(vector<vector<int>> &adjList, vector<int> &bobVisitedTime, int source, int target, int parent, int time) {
          bobVisitedTime[source] = time;
          if(source == target) 
              return true;
              
          for(auto child : adjList[source]) {
              if(child == parent)  continue;
  
              if(fillPathToRoot(adjList, bobVisitedTime, child, target, source, time + 1))    
                  return true;
          }
  
          bobVisitedTime[source] = -1;   
          return false;
      }
  };