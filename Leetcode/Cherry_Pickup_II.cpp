#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // int dp[71][71][71];

    // int findTotalCherry(int n, int m, vector<vector<int>> &grid, int row, int robo1, int robo2){

    //     // Base Case
    //     if(row == n)
    //         return 0;

    //     if(dp[row][robo1][robo2] != -1)
    //         return dp[row][robo1][robo2];

    //     int result = 0;
    //     int yPos[3] = {-1, 0, 1};

    //     // Robot 1 choices
    //     for(int j=0; j<3; j++){
    //         int y = robo1 + yPos[j];
            
    //         if(y >= 0 && y < m){

    //             // Robot 2 choices
    //             for(int k=0; k<3; k++){
    //                 int z = robo2 + yPos[k];

    //                 // Both can not collect same cell
    //                 if(z >= 0 && z < m && y != z){

    //                     int call = grid[row][robo1] + grid[row][robo2] + findTotalCherry(n, m, grid, row + 1, y, z);
    //                     result = max(result, call);
    //                 }
    //             }
    //         }
    //     }

    //     return dp[row][robo1][robo2] = result;
    // }

    // int cherryPickup(vector<vector<int>>& grid) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     memset(dp, -1, sizeof(dp));

    //     return findTotalCherry(n, m, grid, 0, 0, m-1);
    // }

    int dp[72][72][72];

    // int findTotalCherry(int n, int m, vector<vector<int>> &grid, int row, int robo1, int robo2){

    //     // Base Case
    //     if(row == n)
    //         return 0;

    //     if(dp[row][robo1][robo2] != -1)
    //         return dp[row][robo1][robo2];

    //     int result = 0;
    //     int yPos[3] = {-1, 0, 1};

    //     // Robot 1 choices
    //     for(int j=0; j<3; j++){
    //         int y = robo1 + yPos[j];
            
    //         if(y >= 0 && y < m){

    //             // Robot 2 choices
    //             for(int k=0; k<3; k++){
    //                 int z = robo2 + yPos[k];

    //                 // Both can not collect same cell
    //                 if(z >= 0 && z < m && y != z){

    //                     int call = grid[row][robo1] + grid[row][robo2] + findTotalCherry(n, m, grid, row + 1, y, z);
    //                     result = max(result, call);
    //                 }
    //             }
    //         }
    //     }

    //     return dp[row][robo1][robo2] = result;
    // }

    // int cherryPickup(vector<vector<int>>& grid) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     // memset(dp, 0, sizeof(dp));
    //     // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (m+1, 0)));

    //     vector<vector<int>> prev(m + 1, vector<int> (m + 1));
    //     vector<vector<int>> curr(m + 1, vector<int> (m + 1));

    //     for(int row=n-1; row>=0; row--){

    //         for(int robo1=0; robo1<=m; robo1++){

    //             for(int robo2=m; robo2>=0; robo2--){

    //                 if(robo1 == m || robo2 == m){
    //                     curr[robo1][robo2] = 0;
    //                     continue;
    //                 }

    //                 int result = 0;

    //                 // Robot 1 choices
    //                 for(int j=0; j<3; j++){
    //                     int y = robo1 + yPos[j];
                        
    //                     if(y >= 0 && y < m){

    //                         // Robot 2 choices
    //                         for(int k=0; k<3; k++){
    //                             int z = robo2 + yPos[k];

    //                             // Both can not collect same cell
    //                             if(z >= 0 && z < m && y != z){

    //                                 int call = grid[row][robo1] + grid[row][robo2] + prev[y][z];
    //                                 result = max(result, call);
    //                             }
    //                         }
    //                     }
    //                 }

    //                 curr[robo1][robo2] = result;
    //             }
    //         }

    //         prev = curr;
    //     }

    //     return prev[0][m-1];
    // }

    int cherryPickup(vector<vector<int>>& grid) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        int dp[n + 1][m + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        int yPos[3] = {-1, 0, 1};

        for(int row=n-1; row>=0; row--){

            for(int robo1=0; robo1<m; robo1++){

                for(int robo2=m-1; robo2>=0; robo2--){

                    int result = 0;

                    // Robot 1 choices
                    for(int j=0; j<3; j++){
                        int y = robo1 + yPos[j];
                        
                        if(y >= 0 && y < m){

                            // Robot 2 choices
                            for(int k=0; k<3; k++){
                                int z = robo2 + yPos[k];

                                // Both can not collect same cell
                                if(z >= 0 && z < m && y != z){

                                    int call = grid[row][robo1] + grid[row][robo2] + dp[row+1][y][z];
                                    result = max(result, call);
                                }
                            }
                        }
                    }

                    dp[row][robo1][robo2] = result;
                }
            }
        }

        return dp[0][0][m-1];
    }
};