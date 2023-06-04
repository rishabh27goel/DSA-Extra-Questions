#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Using Queue 
// Time : O(n * m * (n + m))  
// Space : O(n * m)
// void setZeros(vector< vector<int> > &matrix){

//     int n = matrix.size();
//     int m = matrix[0].size();

//     queue< pair<int, int> > q;

//     for(int i=0; i<n; i++){

//         for(int j=0; j<m; j++){

//             if(matrix[i][j] == 0)
//                 q.push(make_pair(i, j));
//         }
//     }


//     while(!q.empty()){

//         pair<int, int> pr = q.front();
//         q.pop();

//         for(int i=0; i<n; i++){

//             matrix[i][pr.second] = 0;
//         }

//         for(int i=0; i<m; i++){

//             matrix[pr.first][i] = 0;
//         }
//     }
// }

// Using Set
// Time : O((n * m) + (n + m))  => O(n * m)
// Space : O(n + m)
// void setZeros(vector< vector<int> > &matrix){

//     int n = matrix.size();
//     int m = matrix[0].size();

//     unordered_set<int> rowSet;
//     unordered_set<int> colSet;

//     for(int i=0; i<n; i++){

//         for(int j=0; j<m; j++){

//             if(matrix[i][j] == 0){

//                 rowSet.insert(i);
//                 colSet.insert(j);
//             }
//         }
//     }

//     for(auto itr = rowSet.begin(); itr != rowSet.end(); itr++){

//         for(int i=0; i<m; i++){

//             matrix[*(itr)][i] = 0;
//         }
//     }

//     for(auto itr = colSet.begin(); itr != colSet.end(); itr++){

//         for(int i=0; i<n; i++){

//             matrix[i][*(itr)] = 0;
//         }
//     }   
// }

// Space Optimised
// Time : O(n * m)
// Space : O(1)
void setZeros(vector< vector<int> > &matrix){

    int n = matrix.size();
    int m = matrix[0].size();

    
    bool firstCol = false;

    for(int i=0; i<n; i++){

        if(matrix[i][0] == 0)
            firstCol = true;


        for(int j=1; j<m; j++){

            if(matrix[i][j] == 0){

                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for(int i=n-1; i>=0; i--){

        for(int j=m-1; j>=1; j--){

            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }

        if(firstCol == true)
            matrix[i][0] = 0;
    }
}

int main()
{
    cout << "Enter size : ";
    int n, m;
    cin >> n >> m;


    vector< vector<int> > matrix(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> matrix[i][j];
        }
    }


    setZeros(matrix);

    cout << "Print Matrix : \n";

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }


    cout << endl;
    return 0;
}