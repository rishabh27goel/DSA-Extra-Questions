#include <iostream>
#include <vector>
#include <queue>
#include "Graph.h"
using namespace std;

void bfs(int n, vector< vector<int> > &adjList, vector<bool> &visited, int src) {
    queue <int> nodes;
    nodes.push(src);

    while(!nodes.empty()) {
        int size = nodes.size();
        while(size--) {
            
            int node = nodes.front();
            nodes.pop();
            
            cout << node << " "; 

            for(auto child : adjList[node]) {
                if(!visited[child]) {
                    nodes.push(child);
                    visited[child] = true;
                }
            }
        }
    }
}

void printBFS(int n, vector< vector<int> > &adjList) {

    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            bfs(n, adjList, visited, i);
        }
    }
}

int main () 
{
    cout << "Enter number of vertices : ";
    int n;
    cin >> n;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    Graph graph(n, false);
    // 0 1 0 2 1 4 2 3 3 4 4 6 3 5 5 6
    while(m--) {
        int u, v;
        cin >> u >> v;

        graph.addEdge(u, v);
    }

    vector< vector<int> > &adjList = graph.getAdjacencyList();

    // Print bfs traversal
    printBFS(n, adjList);

    return 0;
}