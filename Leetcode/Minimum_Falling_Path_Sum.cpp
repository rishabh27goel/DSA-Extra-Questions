#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dp[102][102];

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = matrix.size();

        memset(dp, 0, sizeof(dp));

        for(int i=n-1; i>=0; i--){

            for(int j=n-1; j>=0; j--){

                int minSum = INT_MAX;

                if(j - 1 >= 0)
                    minSum = min(minSum, matrix[i][j] + dp[i+1][j-1]);

                minSum = min(minSum, matrix[i][j] + dp[i+1][j]);

                if(j + 1 < n)
                    minSum = min(minSum, matrix[i][j] + dp[i+1][j+1]);

                dp[i][j] = minSum;
            }
        }

        int result = INT_MAX;

        for(int i=0; i<n; i++){

            result = min(dp[0][i], result);
        }

        return result;
    }
};