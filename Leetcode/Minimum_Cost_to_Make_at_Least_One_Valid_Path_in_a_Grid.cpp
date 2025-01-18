#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    pair<int, int> findCoords(int direction) {
        if(direction == 1)
            return make_pair(0, 1);
        
        else if(direction == 2)
            return make_pair(0, -1);
        
        else if(direction == 3)
            return make_pair(1, 0);
        
        else
            return make_pair(-1, 0);
    }

    // int minCost(vector<vector<int>>& grid) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<vector<int>> minCost(n, vector<int> (m, INT_MAX));
    //     minCost[0][0] = 0;

    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPath;
    //     minPath.push(make_pair(0, 0));

    //     int xPos[4] = {1, -1, 0, 0};
    //     int yPos[4] = {0, 0, 1, -1};

    //     while(!minPath.empty()) {
    //         auto topNode = minPath.top();
    //         minPath.pop();

    //         int cost = topNode.first;
    //         int row = topNode.second / m;
    //         int col = topNode.second % m;
    //         auto curr = findCoords(grid[row][col]);

    //         if(row == n-1 && col == m-1)
    //             return cost;
    
    //         for(int k = 0; k < 4; k++) {
    //             int x = xPos[k] + row;
    //             int y = yPos[k] + col;

    //             if(x >= 0 && y >= 0 && x < n && y < m) {
    //                 int val = !(curr.first == xPos[k] && curr.second == yPos[k]);
    //                 if(minCost[x][y] > minCost[row][col] + val) {
    //                     minCost[x][y] = minCost[row][col] + val;
    //                     minPath.push(make_pair(minCost[x][y], x * m + y));
    //                 }
    //             }
    //         }    
    //     }

    //     return minCost[n-1][m-1];
    // }

    int minCost(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> minCost(n, vector<int> (m, INT_MAX));
        minCost[0][0] = 0;

        deque<pair<int, int>> minPath;
        minPath.push_back(make_pair(0, 0));

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        while(!minPath.empty()) {
            auto topNode = minPath.front();
            minPath.pop_front();

            int cost = topNode.first;
            int row = topNode.second / m;
            int col = topNode.second % m;
            auto curr = findCoords(grid[row][col]);

            if(row == n-1 && col == m-1)
                return cost;
    
            for(int k = 0; k < 4; k++) {
                int x = xPos[k] + row;
                int y = yPos[k] + col;

                if(x >= 0 && y >= 0 && x < n && y < m) {
                    int val = !(curr.first == xPos[k] && curr.second == yPos[k]);
                    if(minCost[x][y] > minCost[row][col] + val) {
                        minCost[x][y] = minCost[row][col] + val;

                        if(val == 0)
                            minPath.push_front(make_pair(minCost[x][y], x * m + y));
                        else
                            minPath.push_back(make_pair(minCost[x][y], x * m + y));
                    }
                }
            }    
        }

        return minCost[n-1][m-1];
    }
};