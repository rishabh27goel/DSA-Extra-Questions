#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = heights.size();
        int m = heights[0].size();

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        int maxDiff = 0;
        vector<vector<int>> minEffort(n, vector<int> (m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;

        minHeap.push(make_tuple(0, 0, 0));
        minEffort[0][0] = 0;

        while(!minHeap.empty()){

            auto [effort, row, col] = minHeap.top();
            minHeap.pop();

            if(minEffort[row][col] < effort)
                continue;

            if(row == n-1 && col == m-1)
                return effort;


            for(int k=0; k<4; k++){

                int x = xPos[k] + row;
                int y = yPos[k] + col;

                if(x >= 0 && x < n && y >= 0 && y < m){

                    int diff = max(effort, abs(heights[x][y] - heights[row][col]));
                    
                    if(minEffort[x][y] > diff){

                        minHeap.push(make_tuple(diff, x, y));
                        minEffort[x][y] = diff;
                    }
                }
            }
        }

        return -1;
    }
};