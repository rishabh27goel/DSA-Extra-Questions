#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {

    public:
        int n;
        vector< vector<int> > adjList;

    Graph(int n){

        this->n = n;
        this->adjList = vector< vector<int> > (n);
    }

    void addEdge(int u, int v){

        // Directed
        adjList[u].push_back(v);

        // Undirected
        adjList[v].push_back(u);
    }

    void dfsHelper(vector<bool> &visited, int start, vector<int> &dfsArr){

        dfsArr.push_back(start);
        visited[start] = true;

        for(int i=0; i<adjList[start].size(); i++){

            if(visited[adjList[start][i]] == false){

                dfsHelper(visited, adjList[start][i], dfsArr);
            }
        }
    }

    void dfs(){

        vector<bool> visited(n, false);
        vector<int> dfsArr;

        dfsHelper(visited, 0, dfsArr);

        cout << "\nDFS : ";

        for(int i=0; i<dfsArr.size(); i++){

            cout << dfsArr[i] << " ";
        }
    }

    void bfs(){

        vector<bool> visited(n, false);
        vector<int> bfsArr;

        queue<int> q;

        q.push(0);
        visited[0] = true;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                int start = q.front();
                q.pop();

                bfsArr.push_back(start);

                for(int i=0; i<adjList[start].size(); i++){

                    if(visited[adjList[start][i]] == false){

                        q.push(adjList[start][i]);
                        visited[adjList[start][i]] = true;
                    }
                }
            }
        }


        cout << "\nBFS : ";

        for(int i=0; i<bfsArr.size(); i++){

            cout << bfsArr[i] << " ";
        }
    }
};

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Creating a graph
    Graph g1(n);

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        g1.addEdge(u, v);
    }

    g1.dfs();
    g1.bfs();


    cout << endl;
    return 0;
}