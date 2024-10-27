#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int dp[301][301];
    // int totalSquare = 0;

    // int findSquares(int n, int m, vector<vector<int>> &matrix, int i, int j) {
    //     // Base Case
    //     if(i == n || j == m)
    //         return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     int leftSide = findSquares(n, m, matrix, i, j + 1);
    //     int rightSide = findSquares(n, m, matrix, i + 1, j);
    //     int digSide = findSquares(n, m, matrix, i + 1, j + 1);

    //     int currSquare = 0;
    //     if(matrix[i][j] == 1)
    //         currSquare = 1 + min({leftSide, rightSide, digSide});
        
    //     totalSquare += currSquare;
    //     return dp[i][j] = currSquare;
    // }

    // int countSquares(vector<vector<int>>& matrix) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout .tie(NULL);

    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     memset(dp, -1, sizeof(dp));
    //     findSquares(n, m, matrix, 0, 0);

    //     return totalSquare;
    // }

    int countSquares(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = matrix.size();
        int m = matrix[0].size();

        int totalSquare = 0;
        int dp[301][301];

        memset(dp, 0, sizeof(dp));

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {

                int leftSide = dp[i][j + 1];
                int rightSide = dp[i + 1][j];
                int digSide = dp[i + 1][j + 1];

                int currSquare = 0;
                if(matrix[i][j] == 1)
                    currSquare = 1 + min({leftSide, rightSide, digSide});

                dp[i][j] = currSquare;
                totalSquare += currSquare;
            }
        }

        return totalSquare;
    }
};