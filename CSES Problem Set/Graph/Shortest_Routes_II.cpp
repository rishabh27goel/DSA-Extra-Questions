#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <limits.h>
using namespace std;

#define ll long long

void findShortestPath(int n, vector< vector<ll> > &adjMat) {
    for(int via = 0; via < n; via++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adjMat[i][via] + adjMat[via][j] >= 0)
                    adjMat[i][j] = min(adjMat[i][via] + adjMat[via][j], adjMat[i][j]);
            }
        }
    }
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector< vector<ll> > adjMat(n, vector<ll> (n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                adjMat[i][j] = 0;
            else    
                adjMat[i][j] = LONG_MAX;
        }
    }

    for(int j = 0; j < m; j++) {
        ll u, v, d;
        cin >> u >> v >> d;

        adjMat[u - 1][v - 1] = min(adjMat[u - 1][v - 1], d);
        adjMat[v - 1][u - 1] = adjMat[u - 1][v - 1];
    }

    findShortestPath(n, adjMat);

    for(int j = 0; j < q; j++) {
        ll u, v;
        cin >> u >> v;
    
        cout << ((adjMat[u - 1][v - 1] == LONG_MAX) ? -1 : adjMat[u - 1][v - 1]);
        cout << endl;
    }

    return 0;
}