#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n, 0);

        for(int j = 0; j < prerequisites.size(); j++) {
            int u = prerequisites[j][0];
            int v = prerequisites[j][1];

            inDegree[v]++;
            adjList[u].push_back(v);
        }

        queue<int> nodes;
        for(int j = 0; j < n; j++) {
            if(inDegree[j] == 0)
                nodes.push(j);
        }

        vector<vector<bool>> isPrerequisites(n, vector<bool> (n, false));
        while(!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for(int &child : adjList[node]) {
                isPrerequisites[child][node] = true;
                for(int j = 0; j < n; j++) {
                    if(isPrerequisites[node][j])
                        isPrerequisites[child][j] = true;
                }

                if(--inDegree[child] == 0)
                    nodes.push(child);
            }
        }

        vector<bool> result;
        for(int j = 0; j < queries.size(); j++) {
            int u = queries[j][0];
            int v = queries[j][1];

            result.push_back(isPrerequisites[v][u]);
        }
        return result;
    }
};