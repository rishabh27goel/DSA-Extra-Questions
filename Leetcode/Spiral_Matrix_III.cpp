#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(int &n, int &m, int &row, int &col){
        if(row < 0 || row >= n)
            return false;

        if(col < 0 || col >= m)
            return false;

        return true;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int rowStart = rStart;
        int rowEnd = rStart;
        int colStart = cStart;
        int colEnd = cStart + 1;

        vector<vector<int>> spiralMat;
        spiralMat.push_back({ rStart, cStart });

        int elementsAdded = 1;
        while(elementsAdded < rows * cols){

            for(int k = colStart + 1; k <= colEnd; k++){
                if(isSafe(rows, cols, rowStart, k)){
                    spiralMat.push_back({ rowStart, k });
                    elementsAdded++;
                }
            }

            rowEnd++;
            for(int k = rowStart + 1; k <= rowEnd; k++){
                if(isSafe(rows, cols, k, colEnd)){
                    spiralMat.push_back({ k, colEnd });
                    elementsAdded++;
                }
            }

            colStart--;
            for(int k = colEnd - 1; k >= colStart; k--){
                if(isSafe(rows, cols, rowEnd, k)){
                    spiralMat.push_back({ rowEnd, k });
                    elementsAdded++;
                }
            }

            rowStart--;
            for(int k = rowEnd - 1; k >= rowStart; k--){
                if(isSafe(rows, cols, k, colStart)){
                    spiralMat.push_back({ k, colStart });
                    elementsAdded++;
                }
            }

            colEnd++;
        }

        return spiralMat;
    }
};