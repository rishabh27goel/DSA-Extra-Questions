#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute Force
    // We can flip all the zero to one and check the largest island present

    // Optimised Method (Self Coded)
    // int xPos[4] = {1, -1, 0, 0};
    // int yPos[4] = {0, 0, 1, -1};
    
    // void islandSize(int n, vector<vector<int>> &grid, int row, int col, int counter, int &totalSize) {
    //     grid[row][col] = counter;
    //     totalSize++;

    //     for(int k = 0; k < 4; k++) {
    //         int x = xPos[k] + row;
    //         int y = yPos[k] + col;

    //         if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
    //             islandSize(n, grid, x, y, counter, totalSize);
    //         }
    //     }

    // }

    // int largestIsland(vector<vector<int>>& grid) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = grid.size();

    //     int maxIsland = 0;
    //     int counter = 2;

    //     vector<int> islandSizeMapping = {0, 0};
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < n; j++) {
    //             // Iterate over the island
    //             if(grid[i][j] == 1) {
    //                 int totalSize = 0;
    //                 islandSize(n, grid, i, j, counter, totalSize);

    //                 maxIsland = max(maxIsland, totalSize);
    //                 islandSizeMapping.push_back(totalSize);
    //                 counter++;
    //             }
    //         }
    //     }

    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(grid[i][j] == 0) {
    //                 unordered_set<int> visited;
    //                 int totalNeg = 0;

    //                 for(int k = 0; k < 4; k++) {
    //                     int x = xPos[k] + i;
    //                     int y = yPos[k] + j;

    //                     if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0) {
    //                         if(visited.find(grid[x][y]) == visited.end()) {
    //                             totalNeg += islandSizeMapping[grid[x][y]];
    //                             visited.insert(grid[x][y]);
    //                         }
    //                     }
    //                 }
    //                 maxIsland = max(maxIsland, 1 + totalNeg);
    //             }
    //         }
    //     }
    //     return maxIsland;
    // }

    // Optimised Method (Self Coded)
    int xPos[4] = {1, -1, 0, 0};
    int yPos[4] = {0, 0, 1, -1};
    
    void islandSize(int n, vector<vector<int>> &grid, int row, int col, int counter, int &totalSize) {
        grid[row][col] = counter;
        totalSize++;

        for(int k = 0; k < 4; k++) {
            int x = xPos[k] + row;
            int y = yPos[k] + col;

            if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                islandSize(n, grid, x, y, counter, totalSize);
            }
        }

    }

    int largestIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();

        int maxIsland = 0;
        int counter = 2;

        vector<int> islandSizeMapping = {0, 0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // Iterate over the island
                if(grid[i][j] == 1) {
                    int totalSize = 0;
                    islandSize(n, grid, i, j, counter, totalSize);

                    maxIsland = max(maxIsland, totalSize);
                    islandSizeMapping.push_back(totalSize);
                    counter++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    vector<int> visited;
                    int totalNeg = 0;

                    for(int k = 0; k < 4; k++) {
                        int x = xPos[k] + i;
                        int y = yPos[k] + j;

                        if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0) {
                            visited.push_back(grid[x][y]);
                        }
                    }

                    sort(visited.begin(), visited.end());
                    
                    int j = 0;
                    while(j < visited.size()) {
                        int node = visited[j];
                        while(j < visited.size() && node == visited[j]) {
                            j++;
                        }
                        totalNeg += islandSizeMapping[node];
                    } 

                    maxIsland = max(maxIsland, 1 + totalNeg);
                }
            }
        }
        return maxIsland;
    }
};