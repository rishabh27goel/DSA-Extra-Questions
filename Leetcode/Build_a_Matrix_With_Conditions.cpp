#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    vector<int> findTopologicalOrder(int k, vector<vector<int>>& conditions){

        int e = conditions.size();

        vector<vector<int>> adjList(k);
        vector<int> degree(k, 0);

        for(int i=0; i<e; i++){
            int u = conditions[i][0]-1;
            int v = conditions[i][1]-1;
            
            adjList[u].push_back(v);
            degree[v]++;
        }
    
        // Get topological order
        queue<int> topoQ;
        for(int i=0; i<k; i++){
            if(degree[i] == 0)  topoQ.push(i);
        }

        vector<int> topoOrder;
        while(!topoQ.empty()){

            int node = topoQ.front();
            topoQ.pop();

            topoOrder.push_back(node);
            for(auto child : adjList[node]){

                degree[child]--;
                if(degree[child] == 0)  topoQ.push(child);
            }
        }

        if(topoOrder.size() == k)
            return topoOrder;

        return {};
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        vector<vector<int>> matrix;

        // Find the topological order of row
        vector<int> topoRow = findTopologicalOrder(k, rowConditions);

        // Find the topological order of col
        vector<int> topoCol = findTopologicalOrder(k, colConditions);

        // If not possible
        if(topoRow.empty() || topoCol.empty())
            return matrix;

        matrix.resize(k, vector<int> (k, 0));

        vector<vector<int>> coords(k, vector<int> (2));
        for(int i=0; i<k; i++){
            coords[topoRow[i]][0] = i;
            coords[topoCol[i]][1] = i;
        }

        for(int i=0; i<k; i++){
            matrix[coords[i][0]][coords[i][1]] = i + 1;
        }

        return matrix;
    }
};