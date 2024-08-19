#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <limits.h>
using namespace std;

#define ll long long

void findShortestPath(int n, int m, vector< vector< pair<int, int> > > &adjList, int src) {
    vector<ll> minDistance(n, LLONG_MAX);
    minDistance[src] = 0;

    // priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > minHeap;
    set< pair<ll, int> > minHeap;
    minHeap.insert(make_pair(0, src));

    while(!minHeap.empty()) {
        auto topNode = *(minHeap.begin());
        minHeap.erase(topNode);

        ll distance = topNode.first;
        int currNode = topNode.second;

        for(auto child : adjList[currNode]) {
            if(distance + child.second < minDistance[child.first]) {
                minHeap.erase(make_pair(minDistance[child.first], child.first));
                minDistance[child.first] = distance + child.second;
                minHeap.insert(make_pair(minDistance[child.first], child.first));
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << minDistance[i] << " "; 
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector< vector< pair<int, int> > > adjList(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adjList[u - 1].push_back(make_pair(v - 1, w));
    }

    findShortestPath(n, m, adjList, 0); 
    return 0;
}