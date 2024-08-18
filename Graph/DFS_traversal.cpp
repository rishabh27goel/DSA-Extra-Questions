#include <iostream>
#include <vector>
#include <queue>
#include "Graph.h"
using namespace std;

void dfs(int n, vector< vector<int> > &adjList, vector<bool> &visited, int src) {
    cout << src << " ";
    
    visited[src] = true;
    for(auto child : adjList[src]) {
        if(!visited[child]) {
            dfs(n, adjList, visited, child);
        }
    }
}

void printDFS(int n, vector< vector<int> > &adjList) {
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(n, adjList, visited, i);
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

    // Print dfs traversal
    printDFS(n, adjList);

    return 0;
}