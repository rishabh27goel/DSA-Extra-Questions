#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> heights(n, vector<int> (m, -1));
        queue<int> points;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    points.push(i * m + j);
                }
            }
        }

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        while(!points.empty()) {
            int idx = points.front();
            points.pop();

            int row = idx / m;
            int col = idx % m;

            for(int k = 0; k < 4; k++) {
                int x = xPos[k] + row;
                int y = yPos[k] + col;

                if(x >= 0 && y >= 0 && x < n && y < m && heights[x][y] == -1) {
                    heights[x][y] = heights[row][col] + 1;
                    points.push(x * m + y);
                }
            }
        }

        return heights;
    }
};