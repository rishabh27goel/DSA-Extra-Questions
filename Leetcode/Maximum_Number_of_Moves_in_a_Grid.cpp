#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int dp[1001][1001];
    // int findMoves(int n, int m, vector<vector<int>> &grid, int i, int j) {
    //     // Base Case
    //     if(j >= m)
    //         return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     int above = 0;
    //     if(i - 1 >= 0 && j + 1 < m && grid[i][j] < grid[i - 1][j + 1])
    //         above = 1 + findMoves(n, m, grid, i - 1, j + 1);

    //     int center = 0;
    //     if(j + 1 < m && grid[i][j] < grid[i][j + 1])
    //         center = 1 + findMoves(n, m, grid, i, j + 1);

    //     int below = 0;
    //     if(i + 1 < n && j + 1 < m && grid[i][j] < grid[i + 1][j + 1])
    //         below = 1 + findMoves(n, m, grid, i + 1, j + 1);

    //     return dp[i][j] = max({above, center, below});
    // }

    // int maxMoves(vector<vector<int>>& grid) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     memset(dp, -1, sizeof(dp));

    //     int totalMoves = 0;
    //     for(int i = 0; i < n; i++) {
    //         int moves = findMoves(n, m, grid, i, 0);
    //         totalMoves = max(moves, totalMoves);
    //     }

    //     return totalMoves;
    // }

    int maxMoves(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        int totalMoves = 0;
        for(int j = m-1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                
                int above = 0;
                if(i - 1 >= 0 && j + 1 < m && grid[i][j] < grid[i - 1][j + 1])
                    above = 1 + prev[i - 1];

                int center = 0;
                if(j + 1 < m && grid[i][j] < grid[i][j + 1])
                    center = 1 + prev[i];

                int below = 0;
                if(i + 1 < n && j + 1 < m && grid[i][j] < grid[i + 1][j + 1])
                    below = 1 + prev[i + 1];

                curr[i] = max({above, center, below});
                if(j == 0)  totalMoves = max(totalMoves, curr[i]);
            }

            prev = curr;
        }

        return totalMoves;
    }
};