#include <iostream>
using namespace std;

class Solution {
public:

    const int mod = 1e9 + 7;
    int dp[501][501];

    int findWays(int arrLen, int idx, int steps){

        // Base Case
        if(steps == 0 && idx == 0)
            return 1;
        
        if(idx < 0 || idx >= arrLen || idx > steps || steps == 0)
            return 0;
        

        if(dp[idx][steps] != -1)
            return dp[idx][steps];


        long stay = findWays(arrLen, idx, steps-1);
        long left = findWays(arrLen, idx-1, steps-1);
        long right = findWays(arrLen, idx+1, steps-1);

        return dp[idx][steps] = (stay + left + right) % mod;    
    }

    int numWays(int steps, int arrLen) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        memset(dp, -1, sizeof(dp));

        return findWays(arrLen, 0, steps);
    }
};