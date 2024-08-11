#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Brute Force
    // void bfs(int n, int m, vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
    //     queue<int> pos;
    //     pos.push(i * m + j);
    //     visited[i][j] = true;

    //     while(!pos.empty()){
    //         int size = pos.size();
    //         while(size--){
    //             int node = pos.front();
    //             pos.pop();

    //             int row = node / m;
    //             int col = node % m;

    //             int xPos[4] = {1, -1, 0, 0};
    //             int yPos[4] = {0, 0, 1, -1};

    //             for(int k=0; k<4; k++){
    //                 int x = xPos[k] + row;
    //                 int y = yPos[k] + col;

    //                 if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] == 1){
    //                     pos.push(x * m + y);
    //                     visited[x][y] = true;
    //                 }
    //             }
    //         }
    //     }
    // }


    // int findIsland(int n, int m, vector<vector<int>> &grid){

    //     vector<vector<bool>> visited(n, vector<bool> (m, false));
    //     int island = 0;

    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<m; j++){
    //             if(!visited[i][j] && grid[i][j] == 1){
    //                 bfs(n, m, grid, i, j, visited);
    //                 island++;
    //             }
    //         }
    //     }

    //     return island;
    // }

    // int minDays(vector<vector<int>>& grid) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     int island = findIsland(n, m, grid);
    //     if(island != 1)   return 0;

    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<m; j++){
    //             if(grid[i][j] == 1){
    //                 grid[i][j] = 0;

    //                 int island = findIsland(n, m, grid);
    //                 if(island != 1)   return 1;

    //                 grid[i][j] = 1;
    //             }       
    //         }
    //     }

    //     return 2;
    // }

    void bfs(int n, int m, vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
        queue<int> pos;
        pos.push(i * m + j);
        visited[i][j] = true;

        while(!pos.empty()){
            int size = pos.size();
            while(size--){
                int node = pos.front();
                pos.pop();

                int row = node / m;
                int col = node % m;

                int xPos[4] = {1, -1, 0, 0};
                int yPos[4] = {0, 0, 1, -1};

                for(int k=0; k<4; k++){
                    int x = xPos[k] + row;
                    int y = yPos[k] + col;

                    if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] == 1){
                        pos.push(x * m + y);
                        visited[x][y] = true;
                    }
                }
            }
        }
    }

    int source = 0;
    int findIsland(int n, int m, vector<vector<int>> &grid){
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int island = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    source = i * m + j;
                    bfs(n, m, grid, i, j, visited);
                    island++;
                }
            }
        }

        return island;
    }

    int minDays(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        int islands = findIsland(n, m, grid);
        if(islands != 1) return 0;

        // Now we need to find the articulation points on the grid
        vector<bool> visited(n * m, false);
        vector<int> time(n * m);
        vector<int> low(n * m);

        dfs(n, m, source, -1, visited, time, low, grid);

        cout << artiPoint << " ";

        // If even one point exists then return 1
        return artiPoint == -1 ? 2 : 1;
    }  

    int timer = 0;
    int artiPoint = -1;
    
    void dfs(int n, int m, int src, int parent, vector<bool> &visited, vector<int> &time, vector<int> &low, vector<vector<int>>& grid){
        int row = src / m;
        int col = src % m;

        visited[src] = true;
        time[src] = low[src] = timer++;

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        int childCount = 0;
        for(int k=0; k<4; k++){
            int x = xPos[k] + row;
            int y = yPos[k] + col;
            int child = x * m + y;

            // This will give us all the adjacent nodes 
            if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                if(child == parent) continue;

                if(!visited[child]){
                    dfs(n, m, child, src, visited, time, low, grid);
                    low[src] = min(low[src], low[child]);

                    childCount++;
                    if(time[src] <= low[child] && parent != -1)
                        artiPoint = src;
                }
                else {
                    low[src] = min(low[src], time[child]);
                }
            }
        }
        
        if(childCount != 1 && parent == -1)
            artiPoint = src;
    }
};