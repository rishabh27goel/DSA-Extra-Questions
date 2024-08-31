#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define ll long long int

ll findShortestDistance(int n, vector< vector<ll> > &edges) {
    vector<ll> maxDistance(n, LLONG_MIN);
    maxDistance[0] = 0;

    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < edges.size(); j++) {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll w = edges[j][2];

            if(maxDistance[u] != LLONG_MIN &&maxDistance[u] + w > maxDistance[v]) {
                maxDistance[v] = maxDistance[u] + w;
            }
        }
    }

    ll distanceFirst = maxDistance[n-1];

    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < edges.size(); j++) {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll w = edges[j][2];

            if(maxDistance[u] != LLONG_MIN &&maxDistance[u] + w > maxDistance[v]) {
                maxDistance[v] = maxDistance[u] + w;
            }
        }
    }

    ll distanceSecond = maxDistance[n-1];

    return distanceFirst < distanceSecond ? -1 : distanceSecond;
}

int main()
{
    ll n, m;
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

    cout << findShortestDistance(n, edges);

    return 0;
}