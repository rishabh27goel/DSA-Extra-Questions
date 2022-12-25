#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Taking 2D Vector Space
// Time Complexity : O(n^2)  Space Complexity : O(n^2)
// void printPascalsTriangle(int n){

//     vector< vector<int> > pascals(n);

//     for(int i=0; i<n; i++){

//         pascals[i].resize(i+1);

//         pascals[i][0] = pascals[i][i] = 1; 

//         for(int j=1; j<i; j++){

//             pascals[i][j] = pascals[i-1][j-1] + pascals[i-1][j];
//         }

//         for(int j=0; j<=i; j++){

//             cout << pascals[i][j] << " ";
//         }

//         cout << endl;
//     }
// }

// Method 2 : Taking 1D Vector Space
// Time Complexity : O(n^2)  Space Complexity : O(n)
// void printPascalsTriangle(int n){

//     vector<int> prev;

//     for(int i=0; i<n; i++){

//         vector<int> curr;
//         curr.resize(i+1);

//         curr[0] = curr[i] = 1;

//         for(int j=1; j<i; j++){

//             curr[j] = prev[j-1] + prev[j];
//         }

//         prev = curr;

//         for(int j=0; j<=i; j++){

//             cout << curr[j] << " ";
//         }

//         cout << endl;
//     }
// }

// Method 3 : Taking constant space
// Time Complexity : O(n^2)  Space Complexity : O(1)
void printPascalsTriangle(int n){

    vector<int> prev;

    for(int i=0; i<n; i++){

        int c = 1;

        cout << c << " ";

        for(int j=1; j<=i; j++){

            c = (c * (i - j + 1)) / j;

            cout << c << " ";
        }

        cout << endl;
    }
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    printPascalsTriangle(n);


    cout << endl;
    return 0;
}