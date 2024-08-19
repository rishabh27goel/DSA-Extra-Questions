#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int m, vector<string> &grid, int row, int col) {
    grid[row][col] = '#';

    int xPos[4] = {1, -1, 0, 0};
    int yPos[4] = {0, 0, 1, -1};

    for(int k=0; k<4; k++){
        int x = xPos[k] + row;
        int y = yPos[k] + col;
        
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.') {
            dfs(n, m, grid, x, y);
        }
    }   

}

int findFloors(int n, int m, vector<string> &grid) {
    int components = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.') {
                dfs(n, m, grid, i, j);
                components++;
            }
        }
    }
    return components;
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }

    int components = findFloors(n, m, grid);
    cout << components << endl;

    return 0;
}