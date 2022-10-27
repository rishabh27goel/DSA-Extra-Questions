#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(n * (2 ^ (n * n)))   Space Complexity : O(n)
// int findMinOperations(int n, vector<int> &nums, int i, int j){

//     // Base Case
//     if(j - i <= 1)
//         return 0;


//     int minOperation = INT_MAX;

//     for(int k=i+1; k<j; k++){

//         int oper = findMinOperations(n, nums, i, k) + (nums[i] * nums[k] * nums[j]) + findMinOperations(n, nums, k, j);
    
//         minOperation = min(oper, minOperation);
//     }

//     return minOperation;
// }

// int matrixChainMultiplication(vector<int> &nums){

//     int n = nums.size();

//     return findMinOperations(n, nums, 0, n-1);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * n * n)   Space Complexity : O(n * n)
// int findMinOperations(int n, vector<int> &nums, int i, int j, vector<vector<int>> &dp){

//     // Base Case
//     if(j - i <= 1)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     int minOperation = INT_MAX;

//     for(int k=i+1; k<j; k++){

//         int oper = findMinOperations(n, nums, i, k, dp) + (nums[i] * nums[k] * nums[j]) + findMinOperations(n, nums, k, j, dp);
    
//         minOperation = min(oper, minOperation);
//     }

//     // Step 2 : Store in dp array
//     dp[i][j] = minOperation;


//     return dp[i][j];
// }

// int matrixChainMultiplication(vector<int> &nums){

//     int n = nums.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n, vector<int> (n, -1));


//     return findMinOperations(n, nums, 0, n-1, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * n * n)   Space Complexity : O(n * n)
int matrixChainMultiplication(vector<int> &nums){

    int n = nums.size();

    // Step 1 : Create dp array
    vector<vector<int>> dp(n, vector<int> (n, 0));


    // Step 2 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=i; j<n; j++){

            if(j - i <= 1){

                dp[i][j] = 0;
            }
            else{

                int minOperation = INT_MAX;

                for(int k=i+1; k<j; k++){

                    int oper = dp[i][k] + (nums[i] * nums[k] * nums[j]) + dp[k][j];
                
                    minOperation = min(oper, minOperation);
                }

                dp[i][j] = minOperation;
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter array : ";
    vector<int> nums(size);

    for(int i=0; i<size; i++){

        cin >> nums[i];
    }

    // Matrix Chain Multiplication
    int operations = matrixChainMultiplication(nums);

    cout << "Minimum Operations :  " << operations;


    cout << endl;
    return 0;
}