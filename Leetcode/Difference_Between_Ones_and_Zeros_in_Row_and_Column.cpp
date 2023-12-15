#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                grid[i][j] = (row[i] + col[j] - (n - row[i]) - (m - col[j]));
            }
        }

        return grid;
    }
};