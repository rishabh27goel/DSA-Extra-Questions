#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dst) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<pair<int, double>>> adjList(n);
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j][0];
            int v = edges[j][1];

            adjList[u].push_back({v, succProb[j]});
            adjList[v].push_back({u, succProb[j]});
        } 

        vector<double> maxProb(n, 0);
        maxProb[src] = 0;

        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, src});

        while(!maxHeap.empty()) {
            auto topPair = maxHeap.top();
            maxHeap.pop();

            double currProb = topPair.first;
            int currNode = topPair.second;

            for(auto child : adjList[currNode]) {
                if(currProb * child.second > maxProb[child.first]) {
                    maxProb[child.first] = currProb * child.second;
                    maxHeap.push({maxProb[child.first], child.first});
                }
            }
        }

        return maxProb[dst];
    }
};