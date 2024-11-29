#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        // This edge case is important as we will miss the case having larger cell cost at the start only
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;


        vector<vector<int>> visited(n, vector<int> (m, INT_MAX));
        visited[0][0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minDist;
        minDist.push({0, 0});

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        while(!minDist.empty()) {
            auto topNode = minDist.top();
            minDist.pop();

            int distance = topNode.first;
            int row = topNode.second / m;
            int col = topNode.second % m;

            if(row == n-1 && col == m-1)
                return distance;

            for(int k = 0; k < 4; k++) {
                int x = xPos[k] + row;
                int y = yPos[k] + col;

                if(x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == INT_MAX) {
                    if(distance + 1 >= grid[x][y]) {
                        visited[x][y] = distance + 1;
                        minDist.push({visited[x][y], x * m + y});
                    }
                    else {
                        visited[x][y] = grid[x][y] + ((grid[x][y] - distance - 1) % 2);
                        minDist.push({visited[x][y], x * m + y});
                    }
                }
            }
        }

        return -1;
    }
};