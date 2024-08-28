#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool validIsland = true;
    void getIsland(int n, int m, vector<vector<int>> &leftGrid, vector<vector<int>> &rightGrid, int row, int col) {

        if(leftGrid[row][col] == 0)   validIsland = false;
        rightGrid[row][col] = 0;

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int x = xPos[k] + row;
            int y = yPos[k] + col;
        
            if(x >= 0 && y >= 0 && x < n && y < m && rightGrid[x][y] == 1) {
                getIsland(n, m, leftGrid, rightGrid, x, y);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid1.size();
        int m = grid1[0].size();

        int islandCount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Part of an island
                if(grid2[i][j] == 1) {
                    validIsland = true;
                    getIsland(n, m, grid1, grid2, i, j);

                    if(validIsland)
                        islandCount++;
                }
            }
        }
        return islandCount;
    }
};