#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> connectedNodes;
    bool isBipartite = true;

    int getMaxGroup(int n, vector<vector<int>> &adjList, int start) {
        queue<int> nodes;
        nodes.push(start);

        vector<int> distance(n, -1);
        distance[start] = 1;

        int maxDistance = 1;
        while(!nodes.empty()) {
            int src = nodes.front();
            nodes.pop();

            for(auto &child : adjList[src]) {
                if(distance[child] == -1) {
                    distance[child] = 1 + distance[src];
                    nodes.push(child);
                    maxDistance = max(maxDistance, distance[child]);
                }
            }
        }

        return maxDistance;
    }

    void checkBipartite(int n, vector<vector<int>> &adjList, vector<int> &color, int start, int currColor) {
        color[start] = currColor;
        connectedNodes.push_back(start);

        for(auto &child : adjList[start]) {
            if(color[child] == -1) {
                checkBipartite(n, adjList, color, child, !currColor);
            }
            else {
                if(color[child] == currColor)
                    isBipartite = false;
            }
        }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> adjList(n);
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j][0]-1;
            int v = edges[j][1]-1;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> color(n, -1);
        int maxGroups = 0;

        for(int j = 0; j < n; j++) {
            // If node is not visited
            if(color[j] == -1) {
                connectedNodes.clear();
                isBipartite = true;

                checkBipartite(n, adjList, color, j, 0);
                if(!isBipartite)    
                    return -1;

                int maxComponentGroup = 0;
                for(auto &node : connectedNodes) {
                    int group = getMaxGroup(n, adjList, node);
                    maxComponentGroup = max(maxComponentGroup, group);
                }
                maxGroups += maxComponentGroup;
            }
        }

        return maxGroups;
    }
};