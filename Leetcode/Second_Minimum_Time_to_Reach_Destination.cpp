#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adjList(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Here we dont need second parameter in queue 
        // As for all neighbouring nodes distance is same
        int result = -1;
        int currTime = 0;
        vector<int> shortest(n, -1);
        vector<int> secShortest(n, -1);

        queue<int> nodes;
        nodes.push(0);

        while(!nodes.empty()){

            int size = nodes.size();
            while(size--){
                int node = nodes.front();
                nodes.pop();

                if(node == n-1){
                    if(result != -1)
                        return currTime;

                    result = currTime;
                }

                for(auto child : adjList[node]){
                    if(shortest[child] == -1){
                        shortest[child] = currTime;
                        nodes.push(child);
                    }   
                    else if(secShortest[child] == -1 && currTime != shortest[child]){
                        secShortest[child] = currTime;
                        nodes.push(child);
                    }
                }
            }

        
            int mul = currTime / change;
            // Red light
            if(mul % 2 == 1){
                int rem = change - (currTime % change);
                currTime += rem;
            }

            currTime += time;
        } 

        return -1;
    }
};