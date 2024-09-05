#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void findShortestPath(int n, vector< vector<int> > &adjList) {
    queue<int> nodes;
    nodes.push(0);

    vector<int> visited(n, -1);
    visited[0] = 0;

    while(!nodes.empty()) {
        int currNode = nodes.front();
        nodes.pop();

        for(auto child : adjList[currNode]) {
            if(visited[child] == -1) {
                nodes.push(child);
                visited[child] = currNode;
            }
        }
    }

    if(visited[n-1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        vector<int> path;
        int start = n-1;

        while(start != visited[start]) {
            path.push_back(start + 1);
            start = visited[start];
        }

        path.push_back(start + 1);
        reverse(path.begin(), path.end());
    
        cout << path.size() << endl;
        for(auto node : path) {
            cout << node << " ";
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
        adjList[v-1].push_back(u-1);
    }

    findShortestPath(n, adjList);

    return 0;
}