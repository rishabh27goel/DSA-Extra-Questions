#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(n == 1)
            return 1;

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = trust.size();

        // vector<pair<int, int>> degree(n, make_pair(0, 0));
        vector<int> degree(n, 0);
        int result = -1;

        for(int i=0; i<m; i++){

            int u = trust[i][0] - 1;
            int v = trust[i][1] - 1;

            degree[u]--;
            degree[v]++;
        
            if(degree[v] == n-1)
                result = v;
        }

        if(result != -1 && degree[result] == n-1)
            return result + 1;

        return -1;
    }
};