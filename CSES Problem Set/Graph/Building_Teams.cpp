#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool buildTeamHelper(int n, vector< vector<int> > &adjList, vector<int> &team, int src) {
    queue<int> nodes;
    nodes.push(src);

    team[src] = 0;
    while(!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();

        for(auto child : adjList[node]) {
            if(team[child] == -1) {
                nodes.push(child);
                team[child] = !team[node];
            }
            else {
                // If the team building is not possible
                if(team[child] != !team[node])
                    return false;
            }
        }
    }
    return true;
}

void buildTeam(int n, vector< vector<int> > &adjList) {
    vector<int> team(n, -1);
    bool possible = true;

    for(int j = 0; j < n; j++) {
        if(team[j] == -1) {
            possible = (possible && buildTeamHelper(n, adjList, team, j));
        }
    }

    if(possible) {
        for(int i = 0; i < n; i++) {
            cout << team[i] + 1 << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector< vector<int> > adjList(n);
    for(int j = 0; j < m; j++) {
        int u, v;
        cin >> u >> v;

        adjList[u-1].push_back(v-1);
        adjList[v-1].push_back(u-1);
    }

    buildTeam(n, adjList);



    return 0;
}