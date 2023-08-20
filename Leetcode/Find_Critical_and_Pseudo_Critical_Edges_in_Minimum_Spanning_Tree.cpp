#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    // Find thing we need a disjoint set
    class DisjointSet {

        public:
            vector<int> parent;
            vector<int> rank;

        DisjointSet(int n){

            for(int i=0; i<n; i++){

                parent.push_back(i);
                rank.push_back(0);
            }
        }

        int findParent(int node){

            if(parent[node] == node)
                return node;

            return parent[node] = findParent(parent[node]);
        }

        int doUnion(int u, int v){

            int p1 = findParent(u);
            int p2 = findParent(v);

            // No need to consider
            if(p1 == p2)
                return false;
    
        
            if(rank[p1] == rank[p2]){

                rank[p1]++;
                parent[p2] = p1;
            }
            else if(rank[p1] > rank[p2]){

                parent[p2] = p1;
            }
            else{

                parent[p1] = p2;
            }
        
            return true;
        }
    };


    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int m = edges.size();


        // To get the original index of each edge
        for(int i=0; i<edges.size(); i++){

            edges[i].push_back(i);
        }


        // Sort the edges
        sort(edges.begin(), edges.end(), [&](const vector<int> &v1, const vector<int> &v2){

            return v1[2] < v2[2];
        });


        vector<int> critical;
        vector<int> nonCritical;

        int weight = findMST(n, edges, -1, -1);

        for(int i=0; i<edges.size(); i++){

            if(weight < findMST(n, edges, i, -1)){

                critical.push_back(edges[i][3]);
            }
            else if(weight == findMST(n, edges, -1, i)){

                nonCritical.push_back(edges[i][3]);
            }
        }

        return { critical, nonCritical }; 
    }

    int findMST(int n, vector<vector<int>> &edges, int excludeEdge = -1, int includeEdge = -1){

        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int weight = 0;

        DisjointSet ds(n);

        if(includeEdge != -1){

            weight += edges[includeEdge][2];
            ds.doUnion(edges[includeEdge][0], edges[includeEdge][1]);
        }


        for(int i=0; i<edges.size(); i++){

            // We have to exclude edge
            if(excludeEdge == i)
                continue;

            // Edge we have considered
            if(ds.doUnion(edges[i][0], edges[i][1])){

                weight += edges[i][2];
            } 
        }

        for(int i=0; i<n; i++){

            if(ds.findParent(i) != ds.findParent(0))
                return 1e9;
        }

        return weight;
    }
};