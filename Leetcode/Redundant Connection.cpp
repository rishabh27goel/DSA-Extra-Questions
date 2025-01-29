#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findParent(int node, vector<int> &parent) {
        if(parent[node] == node)
            return parent[node];

        return parent[node] = findParent(parent[node], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = edges.size();

        vector<int> parent;
        for(int j = 0; j < n; j++)
            parent.push_back(j);

        for(int j = 0; j < n; j++) {
            int u = edges[j][0]-1;
            int v = edges[j][1]-1;

            int p1 = findParent(u, parent);
            int p2 = findParent(v, parent);

            if(p1 == p2)
                return edges[j];
            else
                parent[p2] = p1;
        }

        return {};
    }
};