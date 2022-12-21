#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector< vector<int> > &matrix){

    int n = matrix.size();

    // Reverse each row in matrix
    for(int i=0; i<n; i++){

        int x = 0;
        int y = n-1;

        while(x < y){

            swap(matrix[i][x], matrix[i][y]);
            x++;
            y--;
        }
    }

    // Left Diagonal to Right Diagonal Swap
    for(int i=0; i<n; i++){

        for(int j=0; j<(n-i-1); j++){

            swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        }
    }
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector< vector<int> > matrix(n, vector<int> (n));

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            cin >> matrix[i][j];
        }
    }

    rotateMatrix(matrix);

    cout << "Rotated Matrix : \n";

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }


    cout << endl;
    return 0;
}