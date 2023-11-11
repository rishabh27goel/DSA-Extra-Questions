#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Graph {
public:

    vector<vector<pair<int, int>>> adjList;
    int n;

    Graph(int n, vector<vector<int>>& edges) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        this->n = n;
        this->adjList.resize(n);

        for(int i=0; i<edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
        
            adjList[u].push_back(make_pair(v, w));
        }
    }
    
    void addEdge(vector<int> edge) {
        
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
    
        adjList[u].push_back(make_pair(v, w));
    }
    
    int shortestPath(int src, int dst) {

        vector<int> distance(n, INT_MAX);
        set<pair<int, int>> st;

        distance[src] = 0;
        st.insert({ 0, src });


        while(!st.empty()){

            // Get the shortest distance from set
            pair<int, int> shortest = *(st.begin());
            st.erase(st.begin());

            int currDist = shortest.first;
            int node = shortest.second;

            for(auto child : adjList[node]){

                if(distance[child.first] > currDist + child.second){

                    distance[child.first] = currDist + child.second;
                    st.insert({ distance[child.first], child.first });
                }
            }
        }


        if(distance[dst] == INT_MAX)
            return -1;

        return distance[dst];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */