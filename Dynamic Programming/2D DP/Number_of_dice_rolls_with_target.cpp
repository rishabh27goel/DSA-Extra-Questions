#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(k ^ n)  Space Complexity : O(n)
// int findWays(int n, int k, int target ){

//     // Base Case [Count way if target is 0]
//     if(n == 0){

//         if(target == 0)
//             return 1;

//         return 0;
//     }


//     // Count ways for dice rolls
//     int ways = 0;

//     for(int i=1; i<=k; i++){

//         if(i > target)  break;

//         ways += findWays(n-1, k, target-i);
//     }


//     return ways;
// }

// int diceRolls(int n, int k, int target){

//     // If the target is not reachable
//     if(n * k < target)   
//         return 0;

    
//     return findWays(n, k, target);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(k * n * target)  Space Complexity : O(n * target)
// int findWays(int n, int k, int target, vector<vector<int>> &dp){

//     // Base Case [Count way if target is 0]
//     if(n == 0){

//         if(target == 0)
//             return 1;

//         return 0;
//     }

//     // Step 3 : Already Exists
//     if(dp[n][target] != -1)
//         return dp[n][target];


//     // Count ways for dice rolls
//     int ways = 0;

//     for(int i=1; i<=k; i++){

//         if(target - i < 0)  break;

//         ways += findWays(n-1, k, target-i, dp);
//     }

//     // Step 2 : Store in dp array
//     return dp[n][target] = ways;
// }

// int diceRolls(int n, int k, int target){

//     // If the target is not reachable
//     if(n * k < target)   
//         return 0;


//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n+1, vector<int> (target+1, -1));

//     return findWays(n, k, target, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(k * n * target)  Space Complexity : O(n * target)
// int diceRolls(int n, int k, int target){

//     // If the target is not reachable
//     if(n * k < target)   
//         return 0;


//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n+1, vector<int> (target+1, 0));


//     // Step 2 : Tabulation
//     for(int i=0; i<=n; i++){

//         for(int j=0; j<=target; j++){

//             if(i == 0 && j == 0){
                    
//                 dp[i][j] = 1;
//             }
//             else if(i == 0 || j == 0){

//                 dp[i][j] = 0;
//             }
//             else{

//                 int ways = 0;

//                 for(int x=1; x<=k; x++){

//                     if(j - x < 0)  break;

//                     ways += dp[i-1][j-x];
//                 }

//                 dp[i][j] = ways;
//             }
//         }
//     }

//     return dp[n][target];
// }

// Method 4 : Space Optimisation 
// Time Complexity : O(k * n * target)  Space Complexity : O(n * target)
int diceRolls(int n, int k, int target){

    // If the target is not reachable
    if(n * k < target)   
        return 0;


    // Step 1 : Create dp array
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);


    // Step 2 : Tabulation
    for(int i=0; i<=n; i++){

        for(int j=0; j<=target; j++){

            if(i == 0 && j == 0){
                    
                curr[j] = 1;
            }
            else if(i == 0 || j == 0){

                curr[j] = 0;
            }
            else{

                int ways = 0;

                for(int x=1; x<=k; x++){

                    if(j - x < 0)  break;

                    ways += prev[j-x];
                }

                curr[j] = ways;
            }
        }

        prev = curr;
    }


    return prev[target];
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter k : ";
    int k;
    cin >> k;

    cout << "Enter target : ";
    int target;
    cin >> target;

    // Number of Dice Rolls With Target
    int total = diceRolls(n, k, target);

    cout << "Number of dice rolls : " << total;


    cout<< endl;
    return 0;
}