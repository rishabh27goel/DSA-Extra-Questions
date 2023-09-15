#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findDistance(vector<vector<int>>& points, int i, int j){

        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = points.size();

        vector<vector<int>> adjList(n);

        for(int i=0; i<n; i++){

            for(int j=i+1; j<n; j++){

                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }


        int totalWeight = 0;
        int c = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);

        pq.push(make_pair(0, 0));

        while(c < n){

            pair<int, int> least = pq.top();
            pq.pop();

            int weight = least.first;
            int node = least.second;

            if(visited[node])
                continue;


            // If edge is included
            totalWeight += weight;
            visited[node] = true;
            c++;

            for(int i=0; i<adjList[node].size(); i++){

                if(visited[adjList[node][i]] == false){

                    pq.push(make_pair(findDistance(points, node, adjList[node][i]), adjList[node][i]));
                }
            }            
        }

        return totalWeight;
    }

    // int findParent(int node, vector<int> &parent){

    //     if(node == parent[node])
    //         return node;

    //     return parent[node] = findParent(parent[node], parent);
    // }

    // int minCostConnectPoints(vector<vector<int>>& points) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = points.size();

    //     vector<int> parent;
    //     vector<int> nodeRank(n, 0);

    //     for(int i=0; i<n; i++){

    //         parent.push_back(i);
    //     }

    //     int totalWeight = 0;
    //     vector<vector<int>> edges;

    //     for(int i=0; i<n; i++){

    //         for(int j=i+1; j<n; j++){

    //             edges.push_back({ abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j });
    //         }
    //     }


    //     sort(edges.begin(), edges.end());
    
    //     int c = 1;

    //     for(int j=0; j<edges.size() && c < n; j++){

    //         int p1 = findParent(edges[j][1], parent);
    //         int p2 = findParent(edges[j][2], parent);

    //         if(p1 != p2){

    //             totalWeight += edges[j][0];
    //             c++;

    //             if(nodeRank[p1] == nodeRank[p2]){

    //                 parent[p2] = p1;
    //                 nodeRank[p1]++;
    //             }
    //             else if(nodeRank[p1] > nodeRank[p2]){

    //                 parent[p2] = p1;
    //             }
    //             else{

    //                 parent[p1] = p2;
    //             }
    //         }
    //     }

    //     return totalWeight;
    // }
};