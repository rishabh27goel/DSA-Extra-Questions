#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = matrix.size();
        int m = matrix[0].size();

        unordered_map<string, int> freqMap;
        int maxFreq = 0;

        for(int i = 0; i < n; i++) {
            string rowPattern = "";
            for(int j = 0; j < m; j++) {
                rowPattern.push_back(matrix[i][j] == matrix[i][0] ? 'T' : 'F');
            }
            freqMap[rowPattern]++;
            maxFreq = max(maxFreq,freqMap[rowPattern]);
        }

        return maxFreq;
    }
};