#include <iostream>
#include <vector>
using namespace std;

vector<int> getSpiralMatrix(int n, int m, vector< vector<int> > &matrix){

    vector<int> spiral;

    int rowStart = 0;
    int rowEnd = n-1;

    int colStart = 0;
    int colEnd = m-1;


    while(rowStart <= rowEnd && colStart <= colEnd){


        for(int i=colStart; i<=colEnd; i++){

            spiral.push_back(matrix[rowStart][i]);
        }

        rowStart++;

        if(rowStart > rowEnd || colStart > colEnd)
            break;

        for(int i=rowStart; i<=rowEnd; i++){

            spiral.push_back(matrix[i][colEnd]);
        }

        colEnd--;

        if(rowStart > rowEnd || colStart > colEnd)
            break;

        for(int i=colEnd; i>=colStart; i--){

            spiral.push_back(matrix[rowEnd][i]);
        }

        rowEnd--;

        if(rowStart > rowEnd || colStart > colEnd)
            break;

        for(int i=rowEnd; i>=rowStart; i--){

            spiral.push_back(matrix[i][colStart]);
        }

        colStart++;
    }


    return spiral;
}

int main()
{
    cout << "Enter matrix size : ";
    int n, m;
    cin >> n >> m;

    vector< vector<int> > matrix(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> matrix[i][j];
        }
    }


    vector<int> spiral = getSpiralMatrix(n, m, matrix);

    for(int i=0; i<spiral.size(); i++){

        cout << spiral[i] << " ";
    }


    cout << endl;
    return 0;
}