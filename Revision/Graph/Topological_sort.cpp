#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {

    public:
        int n;
        vector< vector<int> > adjList;
        vector<int> degree;

    Graph(int n){

        this->n = n;
        this->adjList = vector< vector<int> > (n);
        this->degree = vector<int> (n, 0);
    }

    void addEdge(int u, int v){

        // Directed
        adjList[u].push_back(v);
        degree[v]++;
    }

    vector<int> findTopologicalOrder(){

        vector<int> topoOrder;

        queue<int> q;

        for(int i=0; i<n; i++){

            if(degree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){

            int start = q.front();
            q.pop();

            topoOrder.push_back(start);

            for(int i=0; i<adjList[start].size(); i++){

                degree[adjList[start][i]]--;

                if(degree[adjList[start][i]] == 0)
                    q.push(adjList[start][i]);
            }
        }

        return topoOrder;
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


    vector<int> topo = g1.findTopologicalOrder();

    cout << "Topological Sort : ";

    for(int i=0; i<topo.size(); i++){

        cout << topo[i] << " ";
    }


    cout << endl;
    return 0;
}