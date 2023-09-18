#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = graph.size();

        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(n, vector<bool> (1 << n));
    
        for(int i=0; i<n; i++){

            q.push(make_tuple(i, (1 << i), 0));
            visited[i][(1 << i)] = true;
        }

        while(!q.empty()){

            auto [node, mask, distance] = q.front();
            q.pop();

            if(mask == (1 << n)-1)
                return distance;                            
        
            for(auto child : graph[node]){

                int child_mask = mask | (1 << child);

                if(!visited[child][child_mask]){

                    q.push(make_tuple(child, child_mask, distance+1));
                    visited[child][child_mask] = true;
                }
            }
        }

        return -1;
    }
};