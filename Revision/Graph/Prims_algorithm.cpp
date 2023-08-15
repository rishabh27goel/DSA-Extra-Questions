#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// Using Priority Queue
// Time : O(E * log (V))  Space : O(V + E)
int minimumSpanningTree(int n, int m, vector< vector<int> > &edges){

    vector< vector< pair<int, int> > > adjList(n);

    for(int i=0; i<m; i++){

        adjList[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adjList[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }


    int totalSum = 0;

    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> visited(n, false);
        
    pq.push(make_pair(0, 0));

    while(!pq.empty()){

        pair<int, int> least = pq.top();
        pq.pop();

        int w = least.first;
        int node = least.second;

        if(visited[node])
            continue;


        visited[node] = true;
        totalSum += w;

        for(int i=0; i<adjList[node].size(); i++){

            if(visited[adjList[node][i].first] == false){

                pq.push(make_pair(adjList[node][i].second, adjList[node][i].first));
            }
        }
    }

    return totalSum;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter the number of edges : ";
    int m;
    cin >> m;

    vector< vector<int> > edges;

    for (int i = 0; i < m; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;

        vector<int> sub;
        sub.push_back(u);
        sub.push_back(v);
        sub.push_back(w);

        edges.push_back(sub);
    }
    

    int minSum = minimumSpanningTree(n, m, edges);

    cout << "Minimum Sum : " << minSum;

    cout << endl;
    return 0;
}