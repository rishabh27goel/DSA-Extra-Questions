#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int mod = 1e9 + 7;

void findTopoSort(int n, vector< vector<int> > &adjList, vector<int> &topo) {
    vector<int> degree(n, 0);
    for(int j = 0; j < n; j++) {
        for(int child : adjList[j]) {
            degree[child]++;
        }
    }

    queue<int> nodes;
    for(int j = 0; j < n; j++)
        if(degree[j] == 0)
            nodes.push(j);

    while(!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();

        topo.push_back(node);

        for(auto child : adjList[node]) {
            degree[child]--;
            if(degree[child] == 0)
                nodes.push(child);
        }
    }
}

int findTotalWays(int n, vector< vector<int> > &adjList) {
    vector<int> topoSort;
    findTopoSort(n, adjList, topoSort);

    vector<long> ways(n, 0);
    ways[0] = 1;

    for(int node : topoSort) {
        for(int child : adjList[node]) {
            ways[child] = (ways[child] + ways[node]) % mod;
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