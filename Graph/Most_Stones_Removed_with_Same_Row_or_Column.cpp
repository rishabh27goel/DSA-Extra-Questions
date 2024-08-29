#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public: 
    // void dfs(int n, vector<vector<int>> &adjList, int src, vector<bool> &visited) {
    //     visited[src] = true;
    //     for(auto child : adjList[src]) {
    //         if(!visited[child]) {
    //             dfs(n, adjList, child, visited);
    //         }
    //     }
    // }

    // int removeStones(vector<vector<int>>& stones) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = stones.size();

    //     vector<vector<int>> adjList(n);
    //     for(int i = 0; i < n; i++) {
    //         for(int j = i + 1; j < n; j++) {
    //             if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
    //                 adjList[i].push_back(j);
    //                 adjList[j].push_back(i);
    //             }
    //         }
    //     }

    //     vector<bool> visited(n, false); 
    //     int component = 0;

    //     for(int j = 0; j < n; j++) {
    //         if(!visited[j]) {
    //             dfs(n, adjList, j, visited);
    //             component++;
    //         }
    //     }

    //     return n - component;
    // }

    // int findParent(int node, vector<int> &parent) {
    //     if(node == parent[node])
    //         return node;

    //     return parent[node] = findParent(parent[node], parent);
    // }

    // int removeStones(vector<vector<int>>& stones) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = stones.size();

    //     vector<int> parent;
    //     for(int j = 0; j < n; j++)
    //         parent.push_back(j);

    //     vector<vector<int>> adjList(n);
    //     for(int i = 0; i < n; i++) {
    //         for(int j = i + 1; j < n; j++) {
    //             if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
    //                 int p1 = findParent(i, parent);
    //                 int p2 = findParent(j, parent);

    //                 if(p1 != p2) {
    //                     parent[p2] = p1;
    //                 }
    //             }
    //         }
    //     }

    //     vector<int> tmp(n, -1);
    //     int component = 0;

    //     for(int j = 0; j < n; j++) {
    //         int p = findParent(j, parent);
    //         if(tmp[p] == -1) {
    //             tmp[p] = p;
    //             component++;
    //         }
    //     }

    //     return n - component;
    // }

    int size = 20002;
    int findParent(int node, vector<int> &parent) {
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    int removeStones(vector<vector<int>>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = stones.size();

        vector<int> parent;
        for(int j = 0; j < size; j++)
            parent.push_back(j);
 
        for(int i = 0; i < n; i++) {
            int u = stones[i][0];
            int v = 10001 + stones[i][1];

            int p1 = findParent(u, parent);
            int p2 = findParent(v, parent);

            if(p1 != p2) {
                parent[p2] = p1;
            }
        }

        unordered_set<int> component;
        for(int j = 0; j < n; j++) {
            int u = stones[j][0];

            int p = findParent(u, parent);
            component.insert(p);
        }

        return n - component.size();
    }
};