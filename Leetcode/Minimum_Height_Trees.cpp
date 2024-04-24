#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int m = edges.size();

        if(m == 0)
            return {0};

        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);

        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            degree[v]++;
            degree[u]++;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }    

        queue<int> q;

        for(int i=0; i<n; i++){
            if(degree[i] == 1){
                q.push(i);
                degree[i]--;
            }   
        }

        vector<int> result;

        while(!q.empty()){

            vector<int> level;
            result.clear();

            int size = q.size();

            while(size--){

                int node = q.front();
                q.pop();

                level.push_back(node);

                for(auto child : adjList[node]){

                    if(degree[child] == 0)
                        continue;

                    degree[child]--;

                    if(degree[child] == 1)
                        q.push(child);
                }
            }

            result = level;
        }

        return result;
    }
};