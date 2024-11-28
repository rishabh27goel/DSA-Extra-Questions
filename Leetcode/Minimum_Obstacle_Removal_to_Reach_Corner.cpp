#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
    // int minimumObstacles(vector<vector<int>>& grid) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<vector<int>> minObs(n, vector<int> (m, INT_MAX));
    //     minObs[0][0] = 0;

    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minDist;
    //     minDist.push({0, 0});

    //     int xPos[4] = {1, -1, 0, 0};
    //     int yPos[4] = {0, 0, 1, -1};

    //     while(!minDist.empty()) {
    //         auto topNode = minDist.top();
    //         minDist.pop();

    //         int currDist = topNode.first;
    //         int row = topNode.second / m;
    //         int col = topNode.second % m;
            
    //         if(row == n-1 && col == m-1)
    //             return currDist;

    //         for(int k = 0; k < 4; k++) {
    //             int x = xPos[k] + row;
    //             int y = yPos[k] + col;

    //             if(x >= 0 && y >= 0 && x < n && y < m) {
    //                 if(minObs[x][y] > minObs[row][col] + grid[row][col]) {
    //                     minObs[x][y] = minObs[row][col] + grid[row][col];
    //                     minDist.push({minObs[x][y], x * m + y});
    //                 }
    //             }
    //         }
    //     }

    //     return minObs[n-1][m-1];
    // }

    // int minimumObstacles(vector<vector<int>>& grid) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<vector<int>> minObs(n, vector<int> (m, INT_MAX));
    //     minObs[0][0] = 0;

    //     queue<pair<int, int>> minDist;
    //     minDist.push({0, 0});

    //     int xPos[4] = {0, 0, 1, -1};
    //     int yPos[4] = {1, -1, 0, 0};

    //     while(!minDist.empty()) {
    //         auto topNode = minDist.front();
    //         minDist.pop();

    //         int currDist = topNode.first;
    //         int row = topNode.second / m;
    //         int col = topNode.second % m;
            
    //         for(int k = 0; k < 4; k++) {
    //             int x = xPos[k] + row;
    //             int y = yPos[k] + col;

    //             if(x >= 0 && y >= 0 && x < n && y < m && minObs[x][y] == INT_MAX) {
    //                 minObs[x][y] = currDist + grid[x][y];
    //                 minDist.push({minObs[x][y], x * m + y});
    //             }
    //         }
    //     }

    //     return minObs[n-1][m-1];
    // }

    int minimumObstacles(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> minObs(n, vector<int> (m, INT_MAX));
        minObs[0][0] = 0;

        deque<pair<int, int>> minDist;
        minDist.push_front({0, 0});

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        while(!minDist.empty()) {
            auto topNode = minDist.front();
            minDist.pop_front();

            int currDist = topNode.first;
            int row = topNode.second / m;
            int col = topNode.second % m;
            
            if(row == n-1 && col == m-1)
                return currDist;

            for(int k = 0; k < 4; k++) {
                int x = xPos[k] + row;
                int y = yPos[k] + col;

                if(x >= 0 && y >= 0 && x < n && y < m) {
                    if(minObs[x][y] == INT_MAX) {
                        minObs[x][y] = minObs[row][col] + grid[x][y];

                        if(grid[x][y])
                            minDist.push_back({minObs[x][y], x * m + y});
                        else
                            minDist.push_front({minObs[x][y], x * m + y});
                    }
                }
            }
        }

        return minObs[n-1][m-1];
    }
};