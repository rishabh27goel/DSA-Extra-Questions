#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// // Using Dijkstra Algorithm [Priority Queue]
// // Time : O(E * log(V))  Space : O(E + V)
// vector<int> dijkstraAlgorithm(int n, int m, vector< vector<int> > &edges, int src){

//     // Create adjacency list
//     vector< vector< pair<int, int> > > adjList(n);

//     for(int i=0; i<m; i++){

//         adjList[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
//         adjList[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
//     }

//     // Use of priority queue
//     priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
//     vector<int> shortest(n, INT_MAX);
    
//     shortest[src] = 0;
//     pq.push({ 0, src });


//     while(!pq.empty()){

//         pair<int, int> least = pq.top();
//         pq.pop();

//         int distance = least.first;
//         int node = least.second;

//         for(int i=0; i<adjList[node].size(); i++){

//             if(shortest[adjList[node][i].first] > distance + adjList[node][i].second){

//                 shortest[adjList[node][i].first] = distance + adjList[node][i].second;
//                 pq.push({ shortest[adjList[node][i].first],  adjList[node][i].first });
//             }
//         }
//     }

//     return shortest;
// }

// Using Dijkstra Algorithm [Using Set]
// Time : O(E * log(V))  Space : O(E + V)
vector<int> dijkstraAlgorithm(int n, int m, vector<vector<int>> &edges, int src)
{

    // Create adjacency list
    vector<vector<pair<int, int>>> adjList(n);

    for (int i = 0; i < m; i++)
    {

        adjList[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adjList[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }

    // Uisng Set
    set<pair<int, int>> st;
    vector<int> shortest(n, INT_MAX);

    shortest[src] = 0;
    st.insert({0, src});

    while (!st.empty())
    {

        pair<int, int> least = *(st.begin());

        int distance = least.first;
        int node = least.second;

        st.erase(least);

        for (int i = 0; i < adjList[node].size(); i++)
        {

            if (shortest[adjList[node][i].first] > distance + adjList[node][i].second)
            {

                shortest[adjList[node][i].first] = distance + adjList[node][i].second;
                st.insert({shortest[adjList[node][i].first], adjList[node][i].first});
            }
        }
    }

    return shortest;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter the number of edges : ";
    int m;
    cin >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;
    }

    cout << "Enter source node : ";
    int source;
    cin >> source;

    vector<int> shortest = dijkstraAlgorithm(n, m, edges, source);

    cout << "Shortest Distance : ";

    for (int i = 0; i < shortest.size(); i++)
    {

        cout << shortest[i] << " ";
    }

    cout << endl;
    return 0;
}