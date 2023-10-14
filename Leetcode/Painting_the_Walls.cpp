#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dp[501][501];

    int findMinAmount(int n, vector<int> &cost, vector<int> &time, int idx, int walls){

        // Base Case
        if(walls <= 0)
            return 0;

        if(idx >= n)
            return 1e9;

        if(dp[idx][walls] != -1)
            return dp[idx][walls];

        // Paid Painter
        int paidPainter = cost[idx] + findMinAmount(n, cost, time, idx+1, walls - time[idx] - 1);

        // Free Painter
        int freePainter = findMinAmount(n, cost, time, idx+1, walls);
        

        return dp[idx][walls] = min(paidPainter, freePainter);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = cost.size();

        memset(dp, -1, sizeof(dp));

        return findMinAmount(n, cost, time, 0, n);
    }
};