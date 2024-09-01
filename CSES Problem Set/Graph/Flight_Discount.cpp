#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define ll long long

vector<ll> returnVt(ll val1, ll val2, ll val3) {
    vector<ll> vt;
    vt.push_back(val1);
    vt.push_back(val2);
    vt.push_back(val3);
    return vt;
}
 
ll findShortestPath(int n, vector< vector<ll> > &edges) {

    vector< vector< pair<ll, ll> > > adjList(n);
    for(int j = 0; j < (int) edges.size(); j++) {
        adjList[edges[j][0]].push_back(make_pair(edges[j][1], edges[j][2]));
    }

    priority_queue< vector<ll>, vector< vector<ll> >, greater< vector<ll> > > minHeap;
    minHeap.push(returnVt(0, 0, 0));

    vector<ll> minDistance(n, LLONG_MAX);
    vector<ll> usedTicketDistance(n, LLONG_MAX);
    minDistance[0] = 0;

    while(!minHeap.empty()) {
        auto topVt = minHeap.top();
        minHeap.pop();

        ll distance = topVt[0];
        ll currNode = topVt[1];
        ll ticketUsed = topVt[2];

        if(ticketUsed == 0) {
            if(distance > minDistance[currNode])
                continue;
        }
        else {
            if(distance > usedTicketDistance[currNode])
                continue;
        }
    
        for(auto child : adjList[currNode]) {
            // Case 1: No coupon used yet
            if(!ticketUsed && distance + child.second < minDistance[child.first]) {
                minDistance[child.first] = distance + child.second;
                minHeap.push(returnVt(minDistance[child.first], child.first, 0));
            }

            // Case 2 : We want to use the ticket here
            if(!ticketUsed && distance + (child.second / 2) < usedTicketDistance[child.first]) {
                usedTicketDistance[child.first] = distance + (child.second / 2);
                minHeap.push(returnVt(usedTicketDistance[child.first], child.first, 1));
            }

            // Case 3 : Ticket is already used
            if(ticketUsed && distance + child.second < usedTicketDistance[child.first]) {
                usedTicketDistance[child.first] = distance + child.second;
                minHeap.push(returnVt(usedTicketDistance[child.first], child.first, 1));
            }
        }
    }

   
    return min(minDistance[n-1], usedTicketDistance[n-1]);
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector< vector<ll> > edges;
    for(int j = 0; j < m; j++) {
        ll u, v, w;
        cin >> u >> v >> w;

        vector<ll> edge;
        edge.push_back(u - 1);
        edge.push_back(v - 1);
        edge.push_back(w);

        edges.push_back(edge);
    }

    cout << findShortestPath(n, edges);

    return 0;
}