#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // If we observe carefully this problem is nothing but finding 
    // the nodes which are not part of any cycle
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = graph.size();

    //     vector<vector<int>> adjList(n);
    //     vector<int> degree(n);

    //     queue<int> nodes;
    //     for(int j = 0; j < n; j++) {
    //         for(int child : graph[j]) {
    //             adjList[child].push_back(j);
    //         }
    //         degree[j] = graph[j].size();

    //         if(degree[j] == 0)  nodes.push(j);
    //     }

    //     vector<bool> safeNodes(n, false);
    //     while(!nodes.empty()) {
    //         int node = nodes.front();
    //         nodes.pop();

    //         safeNodes[node] = true;
    //         for(auto child : adjList[node]) {
    //             degree[child]--;

    //             if(degree[child] == 0)
    //                 nodes.push(child);
    //         }
    //     }

    //     vector<int> result;
    //     for(int j = 0; j < n; j++) {
    //         if(safeNodes[j])
    //             result.push_back(j);
    //     }

    //     return result;
    // }

    bool checkCycle(int n, vector<vector<int>>& adjList, vector<bool> &visited, vector<bool> &path, int start) {
        visited[start] = true;
        path[start] = true;

        for(int child : adjList[start]) {
            if(!visited[child]) {
                if(checkCycle(n, adjList, visited, path, child)) {
                    return true;
                }
            }
            else {
                if(path[child])
                    return true;
            }
        }

        path[start] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = graph.size();

        vector<bool> visited(n, false);
        vector<bool> path(n, false);

        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                bool check = checkCycle(n, graph, visited, path, j);
            }
        }

        vector<int> result;
        for(int j = 0; j < n; j++) {
            if(!path[j])
                result.push_back(j);
        }
        return result;
    }
};