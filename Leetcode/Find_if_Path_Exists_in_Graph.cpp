#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // bool isValid(int n, vector<vector<int>> &adjList, int src, int parent, vector<bool> &visited, int dst){

    //     if(src == dst)
    //         return true;

    //     visited[src] = true;

    //     for(int j=0; j<adjList[src].size(); j++){

    //         int child = adjList[src][j];

    //         if(parent != child && visited[child] == false){
    //             if(isValid(n, adjList, child, src, visited, dst)){
    //                 return true;
    //             }
    //         }
    //     }

    //     return false;
    // }

    // bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int m = edges.size();

    //     vector<vector<int>> adjList(n);

    //     for(int i=0; i<m; i++){
    //         int u = edges[i][0];
    //         int v = edges[i][1];
        
    //         adjList[u].push_back(v);
    //         adjList[v].push_back(u);
    //     }


    //     vector<bool> visited(n, false);

    //     if(isValid(n, adjList, src, -1, visited, dst)){
    //         return true;
    //     }

    //     return false;
    // }

    int findParent(int node, vector<int> &parent){

        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = edges.size();

        vector<int> parent;
        for(int i=0; i<n; i++){
            parent.push_back(i);
        }

        for(int i=0; i<m; i++){
            int p1 = findParent(edges[i][0], parent);
            int p2 = findParent(edges[i][1], parent);
        
            if(p1 != p2)
                parent[p2] = p1; 
        }

        return findParent(src, parent) == findParent(dst, parent);
    }
};