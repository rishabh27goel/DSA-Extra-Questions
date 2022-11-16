#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(3 ^ (n * n))  Space Complexity : O(n * n)
// int findMaxSum(int n, vector< vector<int> > &grid, int i, int j){

//     // Base Case
//     if(i == n)
//         return 0;

//     int maxSum = INT_MIN;
//     int pos[3] = {-1, 0, 1};

//     for(int k=0; k<3; k++){

//         int y = pos[k] + j;

//         if(y >= 0 && y <= n-1){

//             int sum = grid[i][j] + findMaxSum(n, grid, i+1, y);
    
//             maxSum = max(sum, maxSum);
//         }
//     }

//     return maxSum;
// }

// int maximumPathSum(vector< vector<int> > &grid){

//     int n = grid.size();

//     int maxSum = INT_MIN;
    
//     for(int i=0; i<n; i++){

//         int sum = findMaxSum(n, grid, 0, i);

//         cout << sum << " ";

//         maxSum = max(sum, maxSum);
//     }
    
//     return maxSum;
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
// int findMaxSum(int n, vector< vector<int> > &grid, int i, int j, vector< vector<int> > &dp){

//     // Base Case
//     if(i == n)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     int maxSum = INT_MIN;
//     int pos[3] = {-1, 0, 1};

//     for(int k=0; k<3; k++){

//         int y = pos[k] + j;

//         if(y >= 0 && y <= n-1){

//             int sum = grid[i][j] + findMaxSum(n, grid, i+1, y, dp);
    
//             maxSum = max(sum, maxSum);
//         }
//     }

//     // Step 2 : Store in dp array
//     dp[i][j] = maxSum;

//     return dp[i][j];
// }

// int maximumPathSum(vector< vector<int> > &grid){

//     int n = grid.size();

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (n, -1));
//     int maxSum = INT_MIN;
    
//     for(int i=0; i<n; i++){

//         int sum = findMaxSum(n, grid, 0, i, dp);

//         maxSum = max(sum, maxSum);
//     }
    
//     return maxSum;
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
// int maximumPathSum(vector< vector<int> > &grid){

//     int n = grid.size();

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n+1, vector<int> (n+1, 0));
    
//     // Step 2 : Tabulation
//     for(int i=n-1; i>=0; i++){

//         for(int j=0; j<n; j++){

//             int pos[3] = {-1, 0, 1};
//             int maxSum = INT_MIN;

//             for(int k=0; k<3; k++){

//                 int y = pos[k] + j;

//                 if(y >= 0 && y <= n-1){

//                     int sum = grid[i][j] + dp[i+1][y];
            
//                     maxSum = max(sum, maxSum);
//                 }
//             }

//             dp[i][j] = maxSum;
//         }
//     }


//     int finalSum = INT_MIN;

//     for(int i=0; i<n; i++){

//         finalSum = max(dp[0][i], finalSum);
//     }

    
//     return finalSum;
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * n)  Space Complexity : O(2 * n)
int maximumPathSum(vector< vector<int> > &grid){

    int n = grid.size();

    // Step 1 : Create dp array
    vector<int> prev(n+1, 0);
    vector<int> curr(n+1, 0);
    
    // Step 2 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=0; j<n; j++){

            int pos[3] = {-1, 0, 1};
            int maxSum = INT_MIN;

            for(int k=0; k<3; k++){

                int y = pos[k] + j;

                if(y >= 0 && y <= n-1){

                    int sum = grid[i][j] + prev[y];
            
                    maxSum = max(sum, maxSum);
                }
            }

            curr[j] = maxSum;
        }

        prev = curr;
    }


    int finalSum = INT_MIN;

    for(int i=0; i<n; i++){

        finalSum = max(prev[i], finalSum);
    }
    
    return finalSum;
}


int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

// Input :
// 10 10  2  0 20  4
// 1  0  0 30  2  5
// 0 10  4  0  2  0
// 1  0  2 20  0  4

    cout << "Enter grid : \n";
    vector< vector<int> > grid(n, vector<int> (n));

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            cin >> grid[i][j];
        }
    }

    // Maximum path sum in matrix
    int sum = maximumPathSum(grid);

    cout << "Maximum Path Sum : " << sum;


    cout << endl;
    return 0;
}