#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int checkSquare(int n, int m, vector<vector<int>> &grid, int row, int col){
        vector<bool> distinct(9, false);
        int firstDiag = 0;
        int secondDiag = 0;

        vector<int> colSum(3, 0);
        for(int i = row; i < row + 3; i++){

            int rowSum = 0;
            for(int j = col; j < col + 3; j++){
                if(grid[i][j] < 1 || grid[i][j] > 9 || distinct[grid[i][j] - 1])
                    return false;

                int x = i - row;
                int y = j - col;

                if(x == y)  firstDiag += grid[i][j];
                if(x + y == 2)  secondDiag += grid[i][j];

                distinct[grid[i][j] - 1] = true;
                rowSum += grid[i][j];
                colSum[j - col] += grid[i][j];
            }

            if(rowSum != 15)   return false;
        }

        if(firstDiag != 15 || secondDiag != 15)  return false;
        for(int i=0; i<3; i++)
            if(colSum[i] != 15)  return false;

        return distinct.size() == 9;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        int total = 0;
        for(int i=0; i<=n-3; i++){
            for(int j=0; j<=m-3; j++){
                if(checkSquare(n, m, grid, i, j))   
                    total++;
            }
        }

        return total;
    }
};