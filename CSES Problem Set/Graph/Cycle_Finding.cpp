#include <iostream>
#include <vector>
#include <limits.h>
#include <utility>
using namespace std;

#define ll long long

vector<ll> returnVt(ll val1, ll val2, ll val3) {
    vector<ll> vt;
    vt.push_back(val1);
    vt.push_back(val2);
    vt.push_back(val3);
    return vt;
}

void findNegativeCycle(int n, vector< vector<ll> > &edges, int src) {
    vector<ll> maxDistance(n, LLONG_MAX);
    maxDistance[src] = 0;

    // Using Bellman ford algorithm
    vector<int> parentTrack(n + 1, -1);

    for(int j = 1; j <= n + 5; j++) {
        for(auto ed : edges) {
            int u = ed[0];
            int v = ed[1];
            ll w = ed[2];

            if(maxDistance[u] != LLONG_MAX && maxDistance[v] > maxDistance[u] + w) {
                maxDistance[v] = maxDistance[u] + w;
                parentTrack[v] = u;
            }
        }
    }

    for(auto ed : edges) {
        int u = ed[0];
        int v = ed[1];
        ll w = ed[2];

        if(maxDistance[u] != LLONG_MAX && maxDistance[v] > maxDistance[u] + w) {
            int start = v;

            // Now we want to enter the cycle
            // v is not necessarily a part of the negative cycle
            for(int j = 0; j < n; j++) {
                start = parentTrack[start];
            }

            vector<int> cycle;
            cycle.push_back(start);

            int startNode = start;
            start = parentTrack[start];

            while(start != startNode) {
                cycle.push_back(start);
                start = parentTrack[start];
            }

            cycle.push_back(start);
            reverse(cycle.begin(), cycle.end());
            
            cout << "YES" << endl;
            for(int j = 0; j < (int) cycle.size(); j++) {
                cout << cycle[j] << " ";
            }

            return;
        }
    }

    cout << "NO" << endl;
    return;
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector< vector<ll> > edges;
    for(int j = 0; j < m; j++) {
        ll u, v, w;
        cin >> u >> v >> w;

        edges.push_back(returnVt(u, v, w));
    }

    // To deal with all nodes
    // Adding a virtual edge with weight zero to each node 
    for(int j = 1; j <= n; j++) {
        edges.push_back(returnVt(0, j, 0));
    }

    findNegativeCycle(n + 1, edges, 0);

    return 0;
}