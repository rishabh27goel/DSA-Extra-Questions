#include <iostream>
using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;
    int dp[51][51][51];

    int findWays(int n, int m, int i, int j, int moves){

        // Base Case
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 1;

        if(moves == 0)
            return 0;

        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];


        int xPos[4] = {-1, 1, 0, 0};
        int yPos[4] = {0, 0, -1, 1};
        long long result = 0;        

        for(int k=0; k<4; k++){

            int x = i + xPos[k];
            int y = j + yPos[k];

            int call = findWays(n, m, x, y, moves-1);
            result = (result + call) % mod;
        }

        return dp[i][j][moves] = result % mod;
    }

    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        
        memset(dp, -1, sizeof(dp));

        return findWays(n, m, startRow, startColumn, maxMove);
    }
};