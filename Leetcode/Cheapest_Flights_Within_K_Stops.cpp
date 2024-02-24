#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        ios_base::sync_with_stdio(false);

        int m = flights.size();

        vector<vector<pair<int, int>>> adjList(n);

        for(int i=0; i<m; i++){

            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
        
            adjList[u].push_back(make_pair(v, w));
        }   

        vector<int> minDist(n, INT_MAX);
        queue<pair<int, int>> q;
        
        q.push(make_pair(src, 0));
        minDist[src] = 0;

        while(!q.empty() && k >= 0){

            int size = q.size();

            while(size--){

                pair<int, int> pr = q.front();
                q.pop();

                int node = pr.first;
                int distance = pr.second; 

                for(int j=0; j<adjList[node].size(); j++){

                    pair<int, int> child = adjList[node][j];

                    if(minDist[child.first] > distance + child.second){

                        minDist[child.first] = distance + child.second;
                        q.push(make_pair(child.first, minDist[child.first]));
                    }
                }
            }

            k--;
        }

        return minDist[dst] == INT_MAX ? -1 : minDist[dst] ;
    }
};