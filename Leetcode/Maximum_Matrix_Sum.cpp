#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Here the trick is that we can make any two number negative number -> positive 
    // Also matrix having zero is a special case
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long matrixSum = 0;
        int negNum = INT_MAX;

        int negCount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] < 0) {
                    negCount++;
                }
                    
                matrixSum += abs(matrix[i][j]);
                negNum = min(abs(matrix[i][j]), negNum);
            }
        }

        if(negCount % 2 == 0)
            return matrixSum;

        return matrixSum - 2 * negNum;
    }
};