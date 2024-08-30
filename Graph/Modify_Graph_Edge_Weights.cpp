#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long findShortestDistance(int n, vector<vector<pair<int, int>>> &adjList, int src, int dst) {
        vector<long long> minDistance(n, LONG_MAX);
        minDistance[src] = 0; 

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
        minHeap.push({0, src});

        while(!minHeap.empty()) {
            auto topPair = minHeap.top();
            minHeap.pop();

            long long distance = topPair.first;
            int currNode = topPair.second;

            for(auto child : adjList[currNode]) {
                if(distance + child.second < minDistance[child.first]) {
                    minDistance[child.first] = distance + child.second;
                    minHeap.push({minDistance[child.first], child.first});
                }
            }
        }

        return minDistance[dst];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dst, int target) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<pair<int, int>>> adjList(n);
        for(auto &edge : edges) {
            if(edge[2] == -1)
                continue;

            adjList[edge[0]].push_back(make_pair(edge[1], edge[2]));
            adjList[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }

        long long currDistance = findShortestDistance(n, adjList, src, dst);
        if(currDistance < target)
            return vector<vector<int>> ();\

        bool exactTarget = (currDistance == target);
        for(auto &edge : edges) {
            if(edge[2] != -1)
                continue;

            // Update edge weight
            edge[2] = (exactTarget ? 1e9 : 1);

            // Add edge to the graph
            adjList[edge[0]].push_back(make_pair(edge[1], edge[2]));
            adjList[edge[1]].push_back(make_pair(edge[0], edge[2]));

            if(!exactTarget) {
                long long newDistance = findShortestDistance(n, adjList, src, dst);
                if(newDistance <= target) {
                    exactTarget = true;
                    edge[2] += (target - newDistance);
                }
            }
        }

        return exactTarget ? edges : vector<vector<int>> ();
    }
};