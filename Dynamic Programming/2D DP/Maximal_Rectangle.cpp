#include <iostream>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<int>> &grid){

    int n = grid.size();
    int m = grid[0].size();

    return 0;
}

int main()
{
    cout << "Enter grid size : ";
    int n, m;
    cin >> n >> m;

    cout << "Enter grid : \n";

    vector<vector<int>> grid(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> grid[i][j];
        }
    }

    // Maximal Rectangle
    int area = maximalRectangle(grid);

    cout << "Maximum Area : " << area;


    cout << endl;
    return 0;
}