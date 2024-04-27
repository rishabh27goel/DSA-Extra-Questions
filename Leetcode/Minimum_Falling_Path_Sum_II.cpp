#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dp[201][201];

    int findMinSum(int n, vector<vector<int>> &grid, int i, int j){

        // Base Case
        if(i == n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int minSum = INT_MAX;

        for(int k=0; k<n; k++){
            if(k != j){
                int sum = grid[i][k] + findMinSum(n, grid, i + 1, k);
                minSum = min(sum, minSum);
            }
        }

        return dp[i][j] = minSum;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = grid.size();

        memset(dp, -1, sizeof(dp));

        int result = INT_MAX;

        for(int i=0; i<n; i++){
            int minSum = grid[0][i] + findMinSum(n, grid, 1, i);
            result = min(minSum, result);
        }

        return result;
    }
};