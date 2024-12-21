#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int component = 0;
    long dfs(int n, vector<vector<int>> &adjList, vector<int> &values, int k, int start, int parent) {
        long totalSum = values[start];

        for(auto child : adjList[start]) {
            if(child == parent) continue;
            totalSum += dfs(n, adjList, values, k, child, start);
        }

        if(totalSum % k == 0)
            component++;

        return totalSum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> adjList(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(n, adjList, values, k, 0, -1);
        return component;
    }
};