#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(n * (2 ^ n))  Space Complexity : O(n)
// int findMinimumMoney(int start, int end){

//     // Base Case
//     if(start >= end)
//         return 0;

//     int minMoney = INT_MAX;

//     for(int i=start; i<=end; i++){

//         // Here we are taking max as we want the amount in which we can guess all the numbers
//         int money = i + max(findMinimumMoney(start, i-1), findMinimumMoney(i+1, end));

//         minMoney = min(money, minMoney);
//     }

//     return minMoney;
// }

// int guessHigherLower(int n){

//     return findMinimumMoney(1, n);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n ^ 3)  Space Complexity : O(n ^ 2)
// int findMinimumMoney(int start, int end, vector<vector<int>> &dp){

//     // Base Case
//     if(start >= end)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[start][end] != -1)
//         return dp[start][end];


//     int minMoney = INT_MAX;

//     for(int i=start; i<=end; i++){

//         // Here we are taking max as we want the amount in which we can guess all the numbers
//         int money = i + max(findMinimumMoney(start, i-1, dp), findMinimumMoney(i+1, end, dp));

//         minMoney = min(money, minMoney);
//     }

//     // Step 2 : Store in dp array
//     dp[start][end] = minMoney;


//     return dp[start][end];
// }

// int guessHigherLower(int n){

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

//     return findMinimumMoney(1, n, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n ^ 3)  Space Complexity : O(n ^ 2)
int guessHigherLower(int n){

    // Step 1 : Create dp array
    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

    // Step 2 : Tabulation
    for(int i=n; i>=1; i--){

        for(int j=i; j<=n; j++){

            if(i == j)
                continue;

            int minMoney = INT_MAX;

            for(int k=i; k<=j; k++){

                // Here we are taking max as we want the amount in which we can guess all the numbers
                int money = k + max(dp[i][k-1], dp[k+1][j]);

                minMoney = min(money, minMoney);
            }

            dp[i][j] = minMoney;
        }
    }

    return dp[1][n];
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Guess Higher and Lower
    int money = guessHigherLower(n);

    cout << "Minimum Money : " << money;

    cout << endl;
    return 0;
}