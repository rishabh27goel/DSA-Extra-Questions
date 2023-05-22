#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    public:
        int n;
        vector< vector<int> > adjList;

    Graph(int n){

        this->n = n;
        this->adjList.resize(n);
    }

    void addEdge(int u, int v){

        adjList[u].push_back(v);

        // Only for Undirected Graph
        // adjList[v].push_back(u);
    }  

    void printAdjacencyList(){

        cout << "\nAdjacency List : " << endl;
        for(int i=0; i<n; i++){

            for(int val : adjList[i]){

                cout << val << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    cout << "Enter size of the graph : ";
    int n;
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    cout << "Enter edges : ";
    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    g.printAdjacencyList();

    cout << endl;
    return 0;
}