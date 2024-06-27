#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = edges.size();

        vector<int> degree(n + 1, 0);
        for(int i=0; i<n; i++){
        
            degree[edges[i][0]-1]++;
            degree[edges[i][1]-1]++;

            if(degree[edges[i][0]-1] == n)
                return edges[i][0];

            if(degree[edges[i][1]-1] == n)
                return edges[i][1];
        }

        return -1;
    }
};