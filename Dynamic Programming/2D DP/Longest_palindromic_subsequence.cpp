#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ (n))  Space Complexity : O(n)
// int findSubsequence(int n, string &str, int i, int j){

//     // Base Case
//     if(i > j)
//         return 0;


//     int length = 0;

//     // If characters are equal
//     if(str[i] == str[j]){

//         int count = findSubsequence(n, str, i+1, j-1);

//         if(i == j){

//             length = 1 + count;
//         }
//         else{

//             length = 2 + count;
//         }
//     }
//     else{

//         int first = findSubsequence(n, str, i+1, j);
//         int second = findSubsequence(n, str, i, j-1);
    
//         length = max(first, second);
//     }


//     return length;
// }

// int longestPalindromicSubsequence(string &str){

//     int n = str.size();

//     return findSubsequence(n, str, 0, n-1);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
// int findSubsequence(int n, string &str, int i, int j, vector<vector<int>> &dp){

//     // Base Case
//     if(i > j)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     int length = 0;

//     // If characters are equal
//     if(str[i] == str[j]){

//         int count = findSubsequence(n, str, i+1, j-1, dp);

//         if(i == j){

//             length = 1 + count;
//         }
//         else{

//             length = 2 + count;
//         }
//     }
//     else{

//         int first = findSubsequence(n, str, i+1, j, dp);
//         int second = findSubsequence(n, str, i, j-1, dp);
    
//         length = max(first, second);
//     }

//     // Step 2 : Store in dp array
//     dp[i][j] = length;

//     return dp[i][j];
// }

// int longestPalindromicSubsequence(string &str){

//     int n = str.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n, vector<int> (n, -1));


//     return findSubsequence(n, str, 0, n-1, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
// int longestPalindromicSubsequence(string &str){

//     int n = str.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n+1, vector<int> (n, 0));

//     // Step 2 : Tabulation
//     for(int i=n-1; i>=0; i--){

//         for(int j=i; j<n; j++){

//             if(i == j){

//                 dp[i][j] = 1;
//             }
//             else{

//                 int length = 0;

//                 // If characters are equal
//                 if(str[i] == str[j]){

//                     int count = dp[i+1][j-1];

//                     if(i == j){

//                         length = 1 + count;
//                     }
//                     else{

//                         length = 2 + count;
//                     }
//                 }
//                 else{

//                     int first = dp[i+1][j];
//                     int second = dp[i][j-1];
                
//                     length = max(first, second);
//                 }

//                 dp[i][j] = length;
//             }
//         }
//     }


//     return dp[0][n-1];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * n)  Space Complexity : O(n)
int longestPalindromicSubsequence(string &str){

    int n = str.size();

    // Step 1 : Create dp array
    vector<int> prev(n+1, 0);
    vector<int> curr(n+1, 0);

    // Step 2 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=i; j<n; j++){

            if(i == j){

                curr[j] = 1;
            }
            else{

                int length = 0;

                // If characters are equal
                if(str[i] == str[j]){

                    int count = prev[j-1];

                    if(i == j){

                        length = 1 + count;
                    }
                    else{

                        length = 2 + count;
                    }
                }
                else{

                    int first = prev[j];
                    int second = curr[j-1];
                
                    length = max(first, second);
                }

                curr[j] = length;
            }
        }

        prev = curr;
    }

    return prev[n-1];
}

// Method 5 : 
// Use Longest Common Subsequence on input string and its reverse string


int main()
{
    cout << "Enter string : ";
    string str;
    cin >> str;

    // Longest Palindromic Subsequence
    int length = longestPalindromicSubsequence(str);

    cout << "Longest Palindromic Subsequence : " << length;


    cout << endl;
    return 0;
}