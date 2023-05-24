#include <iostream>
#include <vector>
using namespace std;

// Using DFS
// Time : O(V + E)  Space : O(V + E)
bool dfs(int n, vector< vector<int> > &adjList, vector<bool> &visited, vector<bool> &dfsExist, int start){
    
    visited[start] = true;
    dfsExist[start] = true;

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == false){

            if(dfs(n, adjList, visited, dfsExist, adjList[start][i])){

                return true;
            }
        }
        else{

            // Loop exist 
            if(dfsExist[adjList[start][i]] == true)
                return true;
        }
    }


    dfsExist[start] = false;
    return false;
}

bool detectCycle(int n, vector< pair<int, int> > &edges){

    vector< vector<int> > adjList(n);

    for(int i=0; i<edges.size(); i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    vector<bool> visited(n, false);
    vector<bool> dfsExists(n, false);

    for(int i=0; i<n; i++){

        if(visited[i] == false){

            if(dfs(n, adjList, visited, dfsExists, i)){

                return true;
            }
        }
    }

    return false;
}

int main()
{   
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    vector< pair<int, int> > edges;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }


    bool exist = detectCycle(n, edges);

    cout << (exist ? "Cycle exist" : "Cycle does not exist");

    cout << endl;
    return 0;
}