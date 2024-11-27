#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int shortestPath(vector<vector<int>> &adjList, vector<int> &shortest, vector<int> &query) {
        int n = adjList.size();

        int u = query[0];
        int v = query[1];

        adjList[u].push_back(v);
        if(1 + shortest[u] < shortest[v]) {
            shortest[v] = shortest[u] + 1;
            minHeap.push({shortest[v], v});
        }

        while(!minHeap.empty()) {
            auto topNode = minHeap.top();
            minHeap.pop();

            int distance = topNode.first;
            int currNode = topNode.second;

            for(auto child : adjList[currNode]) {
                if(shortest[child] > 1 + shortest[currNode]) {
                    shortest[child] = 1 + shortest[currNode];
                    minHeap.push({shortest[child], child});
                }
            }
        }

        return shortest[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();

        vector<vector<int>> adjList(n);
        for(int j = 0; j < n-1; j++) {
            adjList[j].push_back(j + 1);
        }

        // Initial shortest path
        vector<int> shortest;
        for(int i = 0; i < n; i++) {
            shortest.push_back(i);
        }

        vector<int> queryResult;
        for(int i = 0; i < q; i++) {
            int queryVal = shortestPath(adjList, shortest, queries[i]);
            queryResult.push_back(queryVal);
        }
    
        return queryResult;
    }
};