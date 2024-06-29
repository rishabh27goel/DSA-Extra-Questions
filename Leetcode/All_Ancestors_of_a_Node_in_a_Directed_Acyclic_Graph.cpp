#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getAncestor(int n, vector<vector<int>> &adjList, int ancestor, int node, vector<vector<int>> &result){

        for(auto child : adjList[node]){
            if(result[child].empty() || result[child].back() != ancestor){
                result[child].push_back(ancestor);
                getAncestor(n, adjList, ancestor, child, result);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = edges.size();

        vector<vector<int>> adjList(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
        }

        // Fill ancestor node by node
        vector<vector<int>> result(n);
        for(int i=0; i<n; i++){
            getAncestor(n, adjList, i, i, result);
        }

        return result;
    }
};