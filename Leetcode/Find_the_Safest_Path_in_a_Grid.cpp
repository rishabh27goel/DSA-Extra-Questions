#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isSafe(int n, int x, int y){

        if(x < 0 || y < 0 || x >= n || y >= n)
            return false;

        return true;
    }

    bool findPath(int n, vector<vector<int>> &grid, int factor){

        if (grid[0][0] < factor || grid[n - 1][n - 1] < factor)
            return false;

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        vector<vector<int>> visited(n, vector<int> (n, false));
        queue<pair<int, int>> q;

        visited[0][0] = true;
        q.push({0, 0});

        while(!q.empty()){

            pair<int, int> pr = q.front();
            q.pop();

            if(pr.first == n-1 && pr.second == n-1)
                return true;

            for(int k=0; k<4; k++){
                int x = xPos[k] + pr.first;
                int y = yPos[k] + pr.second;

                if(isSafe(n, x, y) && !visited[x][y] && grid[x][y] >= factor){
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        queue<pair<int, int>> thiefQ;
        int maxFactor = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // Add the thief to the queue
                if(grid[i][j] == 1){
                    thiefQ.push(make_pair(i, j));
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = -1;
                }
            }
        }

        // Find the minimum safeness factor for each cell
        while(!thiefQ.empty()){

            pair<int, int> thief = thiefQ.front();
            thiefQ.pop();

            for(int k=0; k<4; k++){
                int x = xPos[k] + thief.first;
                int y = yPos[k] + thief.second;

                if(isSafe(n, x, y) && grid[x][y] == -1){
                    grid[x][y] = grid[thief.first][thief.second] + 1;
                    maxFactor = max(maxFactor, grid[x][y]);
                    thiefQ.push(make_pair(x, y));
                }
            }
        }

        int result = -1;
        int start = 0;
        int end = maxFactor;

        while(start <= end){
            int mid = start + (end - start) / 2;



            if(findPath(n, grid, mid)){
                result = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return result;
    }
};