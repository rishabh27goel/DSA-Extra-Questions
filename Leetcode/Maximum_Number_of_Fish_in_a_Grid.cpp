#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int n, int m, vector<vector<int>> &grid, int row, int col, int &totalFish) {
        totalFish += grid[row][col];
        grid[row][col] = 0;

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int x = xPos[k] + row;
            int y = yPos[k] + col;

            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] > 0) {
                dfs(n, m, grid, x, y, totalFish);
            }
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        int maxFish = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0) {
                    int totalFish = 0;
                    dfs(n, m, grid, i, j, totalFish);

                    maxFish = max(maxFish, totalFish);
                }
            }
        }
        return maxFish;
    }
};