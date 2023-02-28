#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter grid size : ";
    int n, m;
    cin >> n >> m;

    vector< vector<int> > grid(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> grid[i][j];
        }
    }



    cout << endl;
    return 0;
}