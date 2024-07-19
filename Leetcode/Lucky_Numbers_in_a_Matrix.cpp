#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     vector<int> rowMax(n, INT_MAX);
    //     vector<int> colMax(m, INT_MIN);

    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<m; j++){
    //             rowMax[i] = min(rowMax[i], matrix[i][j]);
    //             colMax[j] = max(colMax[j], matrix[i][j]);
    //         }
    //     }

    //     vector<int> result;
    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<m; j++){
    //             if(rowMax[i] == colMax[j]){
    //                 result.push_back(matrix[i][j]);
    //                 return result;
    //             } 
    //         }       
    //     }

    //     return result;
    // }

    // The trick is there is only one lucky number at max
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = matrix.size();
        int m = matrix[0].size();

        // We are trying to find the best maximum candidate
        int maxMinRow = INT_MIN;
        for(int i=0; i<n; i++){

            int minRow = INT_MAX;
            for(int j=0; j<m; j++){
                minRow = min(minRow, matrix[i][j]);
            }

            maxMinRow = max(maxMinRow, minRow);
        }

        int minMaxCol = INT_MAX;
        for(int i=0; i<m; i++){

            int maxRow = INT_MIN;
            for(int j=0; j<n; j++){
                maxRow = max(maxRow, matrix[j][i]);
            }

            minMaxCol = min(minMaxCol, maxRow);
        }

        if(maxMinRow == minMaxCol)
            return {minMaxCol};

        return {};
    }
};