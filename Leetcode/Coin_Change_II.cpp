#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dp[301][5001];

    int findWays(int n, vector<int> &coins, int idx, int amount){

        // Base Case
        if(amount == 0)
            return 1;

        if(amount < 0)
            return 0;

        if(idx == n-1)
            return (amount % coins[idx] == 0);


        if(dp[idx][amount] != -1)
            return dp[idx][amount];


        // int result = 0;

        // for(int i=idx; i<n; i++){

        //     int ways = findWays(n, coins, i, amount - coins[i]);

        //     result += ways;
        // }

        // return dp[idx][amount] = result;

        int include = 0;

        if(amount >= coins[idx])
            include = findWays(n, coins, idx, amount - coins[idx]);


        int exclude = findWays(n, coins, idx + 1, amount);


        return dp[idx][amount] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = coins.size();

        memset(dp, -1, sizeof(dp));

        sort(coins.begin(), coins.end(), greater<int> ());

        return findWays(n, coins, 0, amount);
    }
};