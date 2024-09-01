#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        if(original.size() != n * m)
            return {};

        vector<vector<int>> matrix(n, vector<int> (m));
        for(int j = 0; j < original.size(); j++) {
            int row = j / m;
            int col = j % m;

            matrix[row][col] = original[j];
        }
        return matrix;
    }
};