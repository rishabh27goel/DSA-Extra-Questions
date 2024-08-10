#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // The trick is to convert this question to 0 & 1 grid
    // And find the components in the grid  
    void dfs(int n, vector<vector<int>> &matrix, int row, int col) {
        matrix[row][col] = 1;

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++){
            int x = xPos[k] + row;
            int y = yPos[k] + col;

            if(x >= 0 && y >= 0 && x < n && y < n && matrix[x][y] == 0){
                dfs(n, matrix, x, y);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = grid.size();

        vector<vector<int>> matrix(3 * n, vector<int> (3 * n, 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '/'){
                    for(int x = 3 * i, y = 3 * j + 2; x < 3 * i + 3 && y >= 3 * j; x++, y--){
                        matrix[x][y] = 1;
                    }
                }
                else if(grid[i][j] == '\\'){
                    for(int x = 3 * i, y = 3 * j; x < 3 * i + 3 && y < 3 * j + 3; x++, y++){
                        matrix[x][y] = 1;
                    }
                }
            }
        }

        int regions = 0;
        for(int i = 0; i < 3 * n; i++){
            for(int j = 0; j < 3 * n; j++){
                if(matrix[i][j] == 0){
                    dfs(3 * n, matrix, i, j);
                    regions++;
                } 
            }
        }

        return regions;        
    }
};