#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findTopoSort(int n, vector< vector<int> > &adjList) {
    vector<int> degree(n, 0);
    for(int j = 0; j < n; j++) {
        for(int child : adjList[j]) {
            degree[child]++;
        }
    }

    queue<int> nodes;
    for(int j = 0; j < n; j++) {
        if(degree[j] == 0)
            nodes.push(j);
    }

    vector<int> topoOrder;
    while(!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();

        topoOrder.push_back(node + 1);

        for(int child : adjList[node]) {
            degree[child]--;
            if(degree[child] == 0)
                nodes.push(child);
        }
    }

    if((int) topoOrder.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for(int j = 0; j < topoOrder.size(); j++) {
            cout << topoOrder[j] << " ";
        }
    }
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

    findTopoSort(n, adjList);


    return 0;
}