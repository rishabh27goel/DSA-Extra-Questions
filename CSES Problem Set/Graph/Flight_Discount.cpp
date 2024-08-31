#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

ll findShortestPath(int n, vector< vector<ll> > &edges) {

    vector< vector< pair<ll, ll> > > adjList(n);
    for(int j = 0; j < edges.size(); j++) {
        adjList[edges[j][0]].push_back(make_pair(edges[j][1], edges[j][2]));
    }

    priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll> > > minHeap;
    minHeap.push(make_pair(0, 0));

    vector<ll> minDistance(n, LLONG_MAX);
    minDistance[0] = 0;

    while(!minHeap.empty()) {
        auto topPair = minHeap.top();
        minHeap.pop();

        ll distance = topPair.first;
        ll currNode = topPair.second;
    
        for(auto child : adjList[currNode]) {
            if(distance + child.second < minDistance[child.first]) {
                minDistance[child.first] = distance + child.second;
                minHeap.push(make_pair(minDistance[child.first], child.first));
            }
        }
    }

    for(int j = 0; j < n; j++) {
        cout << minDistance[j] << " ";
    }

    return minDistance[n-1];
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector< vector<ll> > edges;
    for(int j = 0; j < m; j++) {
        ll u, v, w;
        cin >> u >> v >> w;

        vector<ll> edge;
        edge.push_back(u - 1);
        edge.push_back(v - 1);
        edge.push_back(w);

        edges.push_back(edge);
    }

    findShortestPath(n, edges);

    return 0;
}