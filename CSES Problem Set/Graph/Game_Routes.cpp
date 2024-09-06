#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int mod = 1e9 + 7;
int findTotalWays(int n, vector< vector<int> > &adjList) {

    queue<int> nodes;
    nodes.push(0);

    vector<bool> visited(n, false);
    visited[0] = true;

    vector<long> ways(n, 0);
    ways[0] = 1;

    while(!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();

        for(auto child : adjList[node]) {
            if(!visited[child]) {
                nodes.push(child);
                visited[child] = true;
                ways[child] = ways[node];
            }
            else {
                ways[child] = (ways[child] + ways[node]) % mod;
            }
        }
    }

    return ways[n-1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector< vector<int> > adjList(n);
    for(int j = 0; j < m; j++) {
        int u, v;
        cin >> u >> v;

        adjList[u-1].push_back(v-1);
    }

    int ways = findTotalWays(n, adjList);
    cout << ways << endl;

    return 0;
}