#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int size = arr.size();
        int n = mat.size();
        int m = mat[0].size();

        vector<int> idxMap(size);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int idx = i * m + j;
                idxMap[mat[i][j] - 1] = idx;
            }
        }

        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);

        for(int j = 0; j < size; j++) {
            int idx = idxMap[arr[j] - 1];
            int row = idx / m;
            int col = idx % m;

            if(++rowCount[row] == m || ++colCount[col] == n)
                return j;
        }

        return -1;
    }
};