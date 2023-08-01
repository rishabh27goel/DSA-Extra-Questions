#include <iostream>
using namespace std;

class Graph {

    public:
        int n;
        vector< vector<int> > adjList;

    Graph(int n){

        this->n = n;
        this->adjList = vector<vector<int>> (n);
    }

    void addEdge(int u, int v){

        // Directed
        adjList[u].push_back(v);

        // Undirected
        adjList[v].push_back(u);
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


    cout << endl;
    return 0;
}