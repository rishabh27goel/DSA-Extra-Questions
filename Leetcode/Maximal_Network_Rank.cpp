#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        int m = roads.size();

        vector<vector<int>> adjMat(n, vector<int> (n, 0));
        vector<int> degree(n, 0);

        for(int i=0; i<m; i++){

            int u = roads[i][0];
            int v = roads[i][1];

            degree[u]++;
            degree[v]++;

            adjMat[u][v] = 1;
            adjMat[v][u] = 1;
        }


        int result = 0;

        for(int i=0; i<n; i++){

            for(int j=i+1; j<n; j++){

                result = max(degree[i] + degree[j] - adjMat[i][j], result);
            }
        }

        return result;
    }
};