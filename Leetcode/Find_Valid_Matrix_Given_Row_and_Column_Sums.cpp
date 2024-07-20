#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> matrix(n);
        for(int i=0; i<n; i++){

            matrix[i].resize(m);
            for(int j=0; j<m; j++){
                int minVal = min(rowSum[i], colSum[j]);
                rowSum[i] -= minVal;
                colSum[j] -= minVal;
                matrix[i][j] = minVal;
            }
        }

        return matrix;
    }
};