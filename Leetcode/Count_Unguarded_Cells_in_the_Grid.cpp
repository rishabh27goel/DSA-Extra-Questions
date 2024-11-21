#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void makeCell(vector<vector<char>> &grid, vector<int> &cell) {
        int n = grid.size();
        int m = grid[0].size();

        for(int j = cell[1]-1; j >= 0; j--) {
            if(grid[cell[0]][j] == 'G' || grid[cell[0]][j] == 'W')
                break;

            grid[cell[0]][j] = 'V';
        }

        for(int j = cell[1] + 1; j < m; j++) {
            if(grid[cell[0]][j] == 'G' || grid[cell[0]][j] == 'W')
                break;

            grid[cell[0]][j] = 'V';
        }

        for(int i = cell[0] - 1; i >= 0; i--) {
            if(grid[i][cell[1]] == 'G' || grid[i][cell[1]] == 'W')
                break;

            grid[i][cell[1]] = 'V';
        }

        for(int i = cell[0] + 1; i < n; i++) {
            if(grid[i][cell[1]] == 'G' || grid[i][cell[1]] == 'W')
                break;

            grid[i][cell[1]] = 'V';
        }
    }

    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        vector<vector<char>> grid(n, vector<char> (m, '.'));
    
        for(auto &cell : guards) {
            grid[cell[0]][cell[1]] = 'G';
        }

        for(auto &cell : walls) {
            grid[cell[0]][cell[1]] = 'W';
        }

        for(auto &cell : guards) {
            makeCell(grid, cell);
        }

        int cellCount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '.')   cellCount++;
            }
        }

        return cellCount;
    }
};