#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int dp[301][301];
        int totalSquares = 0;
    
        int getSquareCount(int rowSize, int colSize, vector<vector<int>> &matrix, int rowIdx, int colIdx) {
            if(rowIdx >= rowSize || colIdx >= colSize)
                return 0;
    
            if(dp[rowIdx][colIdx] != -1)
                return dp[rowIdx][colIdx];
            
            int rightCall = getSquareCount(rowSize, colSize, matrix, rowIdx, colIdx + 1);
            int downCall = getSquareCount(rowSize, colSize, matrix, rowIdx + 1, colIdx);
            int diagonalCall = getSquareCount(rowSize, colSize, matrix, rowIdx + 1, colIdx + 1);
            
            int currCall = 0;
            if(matrix[rowIdx][colIdx] != 0)
                currCall = 1 + min(diagonalCall, min(rightCall, downCall));
    
            totalSquares += currCall;
            return dp[rowIdx][colIdx] = currCall;
        }
    
        int countSquares(vector<vector<int>>& matrix) {
            int rowSize = matrix.size();
            int colSize = matrix[0].size();
    
            memset(dp, -1, sizeof(dp));
            getSquareCount(rowSize, colSize, matrix, 0, 0);
    
            return totalSquares;
        }
    };