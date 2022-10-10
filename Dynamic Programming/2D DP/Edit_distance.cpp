#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(3 ^ min(n1, n2))  Space Complexity : O(min(n1, n2))
// int findMinimumOperations(int n1, int n2, string &s1, string &s2, int i, int j){

//     // Base Case
//     if(i == n1 && j == n2)
//         return 0;

//     if(i > n1 || j > n2)    
//         return INT_MAX;


//     // Equal Characters
//     int minOp = INT_MAX;

//     if(s1[i] == s2[j]){

//         int equal = findMinimumOperations(n1, n2, s1, s2, i+1, j+1);

//         if(equal != INT_MAX)
//             minOp = min(equal, minOp);
//     }
//     else{

//         int ins = findMinimumOperations(n1, n2, s1, s2, i, j+1);
//         int del = findMinimumOperations(n1, n2, s1, s2, i+1, j);
//         int rep = findMinimumOperations(n1, n2, s1, s2, i+1, j+1);

//         if(ins != INT_MAX)
//             minOp = min(ins+1, minOp);

//         if(del != INT_MAX)
//             minOp = min(del+1, minOp);

//         if(rep != INT_MAX)
//             minOp = min(rep+1, minOp);
//     }

//     return minOp;
// }

// int editDistance(string &s1, string &s2){

//     int n1 = s1.size();
//     int n2 = s2.size();

//     return findMinimumOperations(n1, n2, s1, s2, 0, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n1 * n2)  Space Complexity : O(n1 * n2)
// int findMinimumOperations(int n1, int n2, string &s1, string &s2, int i, int j, vector<vector<int>> &dp){

//     // Base Case
//     if(i == n1 && j == n2)
//         return 0;

//     if(i > n1 || j > n2)    
//         return INT_MAX;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     // Equal Characters
//     int minOp = INT_MAX;

//     if(s1[i] == s2[j]){

//         int equal = findMinimumOperations(n1, n2, s1, s2, i+1, j+1, dp);

//         if(equal != INT_MAX)
//             minOp = min(equal, minOp);
//     }
//     else{

//         int ins = findMinimumOperations(n1, n2, s1, s2, i, j+1, dp);
//         int del = findMinimumOperations(n1, n2, s1, s2, i+1, j, dp);
//         int rep = findMinimumOperations(n1, n2, s1, s2, i+1, j+1, dp);

//         if(ins != INT_MAX)
//             minOp = min(ins+1, minOp);

//         if(del != INT_MAX)
//             minOp = min(del+1, minOp);

//         if(rep != INT_MAX)
//             minOp = min(rep+1, minOp);
//     }

//     // Step 2 : Store in dp array
//     dp[i][j] = minOp;

//     return dp[i][j];
// }

// int editDistance(string &s1, string &s2){

//     int n1 = s1.size();
//     int n2 = s2.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));

//     return findMinimumOperations(n1, n2, s1, s2, 0, 0, dp);
// }

// // Method 3 : Dynamic Programming & Tabulation
// // Time Complexity : O(n1 * n2)  Space Complexity : O(n1 * n2)
// int editDistance(string &s1, string &s2){

//     int n1 = s1.size();
//     int n2 = s2.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n1+2, vector<int> (n2+2, INT_MAX));

//     // Step 2 : Tabulation
//     for(int i=n1; i>=0; i--){

//         for(int j=n2; j>=0; j--){

//             if(i == n1 && j == n2){

//                 dp[i][j] = 0;
//             }
//             else{

//                 // Equal Characters
//                 int minOp = INT_MAX;

//                 if(s1[i] == s2[j]){

//                     int equal = dp[i+1][j+1];

//                     if(equal != INT_MAX)
//                         minOp = min(equal, minOp);
//                 }
//                 else{

//                     int ins = dp[i][j+1];
//                     int del = dp[i+1][j];
//                     int rep = dp[i+1][j+1];

//                     if(ins != INT_MAX)
//                         minOp = min(ins+1, minOp);

//                     if(del != INT_MAX)
//                         minOp = min(del+1, minOp);

//                     if(rep != INT_MAX)
//                         minOp = min(rep+1, minOp);
//                 }

//                 // Step 2 : Store in dp array
//                 dp[i][j] = minOp;
//             }
//         }
//     }

//     return dp[0][0];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n1 * n2)  Space Complexity : O(2 * n2)
int editDistance(string &s1, string &s2){

    int n1 = s1.size();
    int n2 = s2.size();

    // Step 1 : Create dp array
    vector<int> prev(n2+2, INT_MAX);
    vector<int> curr(n2+2, INT_MAX);

    // Step 2 : Tabulation
    for(int i=n1; i>=0; i--){

        for(int j=n2; j>=0; j--){

            if(i == n1 && j == n2){

                curr[j] = 0;
            }
            else{

                // Equal Characters
                int minOp = INT_MAX;

                if(s1[i] == s2[j]){

                    int equal = prev[j+1];

                    if(equal != INT_MAX)
                        minOp = min(equal, minOp);
                }
                else{

                    int ins = curr[j+1];
                    int del = prev[j];
                    int rep = prev[j+1];

                    if(ins != INT_MAX)
                        minOp = min(ins+1, minOp);

                    if(del != INT_MAX)
                        minOp = min(del+1, minOp);

                    if(rep != INT_MAX)
                        minOp = min(rep+1, minOp);
                }

                // Step 2 : Store in dp array
                curr[j] = minOp;
            }
        }

        prev = curr;
    }

    return prev[0];
}

int main()
{
    cout << "Enter first string : ";
    string s1;
    cin >> s1;

    cout << "Enter second string : ";
    string s2;
    cin >> s2;

    // Edit Distance
    int minOp = editDistance(s1, s2);

    cout << "Minimum Operations : " << minOp;

    cout << endl;
    return 0;
}