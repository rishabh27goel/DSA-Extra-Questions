#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void findSubtreeCount(int n, int node, int parent, vector<vector<int>> &adjList, vector<int> &nodeCount){

        int total = 1;

        for(auto child : adjList[node]){
            if(child != parent){    
                findSubtreeCount(n, child, node, adjList, nodeCount);
                // subTrees[node] += (subTrees[child] + nodeCount[child]);
                total += nodeCount[child];
            }
        }

        nodeCount[node] = total;
    }

    void findDistance(int n, int node, int parent, vector<vector<int>> &adjList, vector<int> &nodeCount, vector<int> &result){

        for(auto child : adjList[node]){
            if(child != parent){    
                result[child] += (result[node] + n - (2 * nodeCount[child]));
                findDistance(n, child, node, adjList, nodeCount, result);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = edges.size();

        vector<vector<int>> adjList(n);
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);    
        }

        // vector<int> subTrees(n, 0);
        vector<int> nodeCount(n, 0);
        findSubtreeCount(n, 0, -1, adjList, nodeCount);

        int total = 0;
        for(int i=1; i<n; i++){
            total += nodeCount[i];
        }

        vector<int> result(n);
        result[0] = total;
        findDistance(n, 0, -1, adjList, nodeCount, result);

        return result;
    }
};