#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int src, int dst) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<pair<int, double>>> adjList(n);
        for(int j = 0; j < edges.size(); j++) {
            auto &ed = edges[j];
            adjList[ed[0]].push_back({ed[1], prob[j]});
            adjList[ed[1]].push_back({ed[0], prob[j]});
        }

        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, src});

        vector<double> maxProb(n, 0);
        maxProb[src] = 0.0;

        while(!maxHeap.empty()) {
            auto topPair = maxHeap.top();
            maxHeap.pop();

            double value = topPair.first;
            int currNode = topPair.second;
        
            for(auto child : adjList[currNode]) {
                if(maxProb[child.first] < value * child.second) {
                    maxProb[child.first] = value * child.second;
                    maxHeap.push({maxProb[child.first], child.first});
                }
            }
        } 

        return maxProb[dst];
    }
};