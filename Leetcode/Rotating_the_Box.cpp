#include <iostream>
using namespace std;

class Solution {
public:
    void moveStones(int n, int m, vector<vector<char>> &box, int row, int col) {
        box[row][col] = '.';  
            
        int j = col;
        int newCol = col;

        while(j < m && box[row][j] == '.') {
            newCol = j;
            j++;
        }

        box[row][newCol] = '#';
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = box.size();
        int m = box[0].size();

        for(int j = m-1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                if(box[i][j] == '#')
                    moveStones(n, m, box, i, j);
            }
        }

        vector<vector<char>> boxRot(m, vector<char> (n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                boxRot[j][n-i-1] = box[i][j];
            }
        }
        return boxRot;
    }
};