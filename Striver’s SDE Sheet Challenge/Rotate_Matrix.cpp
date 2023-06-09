#include <iostream>
using namespace std;

// Two step approach
// Time : O(n * m)  Space : O(1)
void rotateMatrix(vector< vector<int> > &grid, int n, int m){

    int rowStart = 0;
    int colStart = 0;

    int rowEnd = n-1;
    int colEnd = m-1;

    while (rowStart < rowEnd && colStart < colEnd) {

        int val = grid[rowStart+1][colStart];

        for (int i = colStart; i <= colEnd; i++) {
      
            int store = grid[rowStart][i];

            grid[rowStart][i] = val;
            val = store;
        }
        
        rowStart++;

        for (int i = rowStart; i <= rowEnd; i++) {
      
            int store = grid[i][colEnd];

            grid[i][colEnd] = val;
            val = store;
        }

        colEnd--;


        for (int i = colEnd; i >= colStart; i--) {
      
            int store = grid[rowEnd][i];

            grid[rowEnd][i] = val;
            val = store;
        }

        rowEnd--;


        for (int i = rowEnd; i >= rowStart; i--) {
      
            int store = grid[i][colStart];

            grid[i][colStart] = val;
            val = store;
        }

        colStart++;
    }
}

int main()
{
    cout << "Enter : ";
    int n, m;
    cin >> n >> m;

    vector< vector<int> > grid(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> grid[i][j];
        }
    }

    rotateMatrix(grid, n, m);


    cout << "Rotated Matrix : \n";

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cout << grid[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}