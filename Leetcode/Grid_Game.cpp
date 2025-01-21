#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        vector<long> firstRow(m);
        vector<long> secondRow(m);

        long sumOne = 0;
        long sumTwo = 0;
        long minResult = LONG_MAX;

        for(int j = m-1; j >= 0; j--) {
            sumOne += grid[0][j];
            firstRow[j] = sumOne;

            sumTwo += grid[1][m - 1 - j];
            secondRow[m - 1 - j] = sumTwo;
        }

        long maxPath = 0;
        long total = firstRow[0] + secondRow[m-1];

        for(int j = 0; j < m; j++) {
            long upper = (j + 1 < m ? firstRow[j + 1] : 0);
            long lower = (j - 1 >= 0 ? secondRow[j - 1] : 0);

            long secondPlayer = max(upper, lower);
            minResult = min(secondPlayer, minResult);                      
        }

        return minResult;
    }
};