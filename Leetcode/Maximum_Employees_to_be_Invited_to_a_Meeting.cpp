#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<int> inDegree(n, 0);
        for(int j = 0; j < n; j++) {
            inDegree[favorite[j]]++;
        }

        queue<int> nodes;
        for(int j = 0; j < n; j++) {
            if(inDegree[j] == 0)
                nodes.push(j);
        }

        vector<int> depth(n, 1);
        while(!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            int next = favorite[node];
            depth[next] = max(depth[next], depth[node] + 1);

            if(--inDegree[next] == 0)
                nodes.push(next);
        }

        int maxEmployee = 0;
        int twoLengthCount = 0;

        for(int person = 0; person < n; person++) {
            if(inDegree[person] == 0)
                continue;

            int cycle = 0;
            int current = person;

            while(inDegree[current] != 0) {
                inDegree[current] = 0;
                current = favorite[current];
                cycle++;
            }

            if(cycle == 2) {
                twoLengthCount += (depth[current] + depth[favorite[current]]);
            }
            else {
                maxEmployee = max(maxEmployee, cycle);
            }
        }

        return max(maxEmployee, twoLengthCount);
    }
};