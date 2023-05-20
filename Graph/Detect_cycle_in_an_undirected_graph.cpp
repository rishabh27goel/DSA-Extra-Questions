#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Breadth First Search
// Time : O(V + E)   Space : O(V + E)
bool detect(int n, vector< vector<int> > &adjList, vector<bool> &visited, int src){

    queue< pair<int, int> > q;

    q.push(make_pair(src, -1));
    visited[src] = true;

    while(!q.empty()){

        int size = q.size();

        while(size--){

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();


            for(int child : adjList[node]){

                if(!visited[child]){

                    q.push(make_pair(child, node));
                    visited[child] = true;
                }
                else{

                    if(child != parent)
                        return true;
                }
            }
        }
    }

    return false;
}

bool detectCycles(int n, vector< pair<int, int> > &edges){

    vector< vector<int> > adjList(n);

    for(int i=0; i<edges.size(); i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(n, false);

    for(int i=0; i<n; i++){

        if(visited[i] == false){

            // If cycle exist
            if(detect(n, adjList, visited, i)){

                return true;
            }
        }
    }

    return false;
}

int main()
{
    cout << "Enter number of nodes : ";
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


    // Detect Cycle
    bool exist = detectCycles(n, edges);

    cout << (exist ? "Cycle exist" : "Cycle does not exist");


    cout << endl;
    return 0;
}