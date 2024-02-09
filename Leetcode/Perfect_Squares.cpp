#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // int dp[10002];

    // int findLeastNumber(int n){

    //     // Base Case
    //     if(n == 0)
    //         return 0;

    //     if(dp[n] != -1)
    //         return dp[n];


    //     int result = n;

    //     for(int j = 1; j * j <= n; j++){

    //         int call = 1 + findLeastNumber(n - (j * j));
            
    //         result = min(call, result);
    //     }

    //     return dp[n] = result;
    // }   

    // int numSquares(int n) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     memset(dp, -1, sizeof(dp));
        
    //     return findLeastNumber(n);
    // }

    int dp[10002];

    int numSquares(int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        memset(dp, 0, sizeof(dp));
        
        for(int idx=1; idx<=n; idx++){

            int result = idx;

            for(int j = 1; j * j <= idx; j++){

                int call = 1 + dp[idx - (j * j)];
                
                result = min(call, result);
            }

            dp[idx] = result;
        }

        return dp[n];
    }
};