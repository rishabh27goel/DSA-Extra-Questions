#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, vector< vector<int> > &adjList, int src, vector<bool> &visited) {
    visited[src] = true;
    for(auto child : adjList[src]) {
        if(!visited[child]) {
            dfs(n, adjList, child, visited);
        }
    }
}

void findMinRoads(int n, vector< vector<int> > &adjList) {
    vector<bool> visited(n, false);
    int prevNode = -1;

    vector< pair<int, int> > roads;
    for(int j = 0; j < n; j++) {
        if(!visited[j]) {
            dfs(n, adjList, j, visited);

            if(prevNode != -1) {
                roads.push_back(make_pair(prevNode, j + 1));
            }
            prevNode = j + 1;
        }
    }

    cout << roads.size() << endl;
    for(int j = 0; j < (int) roads.size(); j++) {
        cout << roads[j].first << " " << roads[j].second << endl;
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

        adjList[u - 1].push_back(v - 1);
        adjList[v - 1].push_back(u - 1);
    }
 
    findMinRoads(n, adjList);

    return 0;
}