#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void findIsland(int n, int m, vector<vector<char>>& grid, int i, int j){

        grid[i][j] = '0';

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        for(int k=0; k<4; k++){
            int x = xPos[k] + i;
            int y = yPos[k] + j;
        
            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '1'){
                findIsland(n, m, grid, x, y);
            }   
        }
    }   

    int numIslands(vector<vector<char>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        int island = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == '1'){
                    findIsland(n, m, grid, i, j);
                    island++;
                }
            }
        }

        return island;
    }
};