#include <iostream>
using namespace std;

#define ll long long

class Solution {
    public:

    ll mod = 1e9 + 7;
    ll dp[301][301];
    ll powStore[301];
    int maxBase = -1;

    ll getTotalWays(ll n, ll x, ll start) {
        if(n == 0)
            return 1;

        if(start > n)
            return 0;


        if(dp[n][start] != -1)
            return dp[n][start];

        ll totalWays = 0;
        for(ll curr = start; curr <= maxBase; curr++) {
            ll currWays = getTotalWays(n - powStore[curr], x, curr + 1);
            totalWays = (totalWays + currWays) % mod;
        }
        return dp[n][start] = totalWays;
    }

    int numberOfWays(int n, int x) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        memset(dp, -1, sizeof(dp));
        memset(powStore, 0, sizeof(powStore));

        int start = 1;
        while(start <= n) {
            ll currPow = pow(start, x);             
            if(currPow > n) break;

            powStore[start] = currPow; 
            maxBase = start;
            start++;      
        }
        return getTotalWays(n, x, 1);
    }
};