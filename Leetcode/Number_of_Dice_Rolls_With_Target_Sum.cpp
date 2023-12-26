#include <iostream>
using namespace std;

class Solution {
public:

    const int mod = 1e9 + 7;
    int dp[31][1001];

    int findWays(int n, int k, int target){

        // Base Case
        if(target < 0)
            return 0;

        if(n == 0)
            return (target == 0);

        if(dp[n][target] != -1)
            return dp[n][target];


        long ways = 0;

        for(int j=1; j<=k; j++){

            ways = (ways + findWays(n-1, k, target-j)) % mod;
        }

        return dp[n][target] = (int) ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        memset(dp, -1, sizeof(dp));

        return findWays(n, k, target);
    }
};