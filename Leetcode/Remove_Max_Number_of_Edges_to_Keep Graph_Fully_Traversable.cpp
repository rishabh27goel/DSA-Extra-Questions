#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    class Disjoint {
        public:
            vector<int> parent;
            vector<int> rank;
            int components;

        Disjoint(int size){
            components = 1;
            for(int i=0; i<size; i++){
                rank.push_back(0);
                parent.push_back(i);
            }
        }

        int findParent(int node){
            if(parent[node] == node)
                return node;

            return findParent(parent[node]);    
        }

        bool edgeUnion(int u, int v){
            int p1 = findParent(u);
            int p2 = findParent(v);
        
            // Union is possible
            if(p1 != p2){
                if(rank[p1] > rank[p2]) {
                    parent[p2] = p1;
                }
                else if(rank[p1] < rank[p2]) {
                    parent[p1] = p2;
                }
                else {
                    rank[p1]++;
                    parent[p2] = p1;
                }

                components++;
                return true;
            }

            return false;
        }
    };


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int total = 0;

        Disjoint alice(n);
        Disjoint bob(n);

        for(int i=0; i<edges.size(); i++){
            int type = edges[i][0];
            int u = edges[i][1]-1;
            int v = edges[i][2]-1;

            // Check for two way edges
            if(type == 3){
                if(!alice.edgeUnion(u, v) || !bob.edgeUnion(u, v))
                    total++;
            }
        }

        for(int i=0; i<edges.size(); i++){
            int type = edges[i][0];
            int u = edges[i][1]-1;
            int v = edges[i][2]-1;

            // Check for two way edges
            if(type == 1){
                if(!alice.edgeUnion(u, v))
                    total++;
            }
            else if(type == 2){
                if(!bob.edgeUnion(u, v))
                    total++;
            }
        }
        
        if(alice.components == n && bob.components == n)
            return total;

        return -1;
    }
};