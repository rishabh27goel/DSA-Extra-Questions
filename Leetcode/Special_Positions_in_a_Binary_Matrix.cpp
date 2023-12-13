#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = mat.size();
        int m = mat[0].size();

        vector<int> rowSum(n, 0);
        vector<int> colSum(m, 0);

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }


        int result = 0;

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(rowSum[i] == 1 && colSum[j] == 1 && mat[i][j] == 1)
                    result++;
            }
        }

        return result;
    }
};