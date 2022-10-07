#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(3 ^ min(n1, n2, n3))  Space Complexity : O(min(n1, n2, n3))
// int findLength(int n1, int n2, int n3, string &s1, string &s2, string &s3, int i, int j, int k){

//     // Base Case
//     if(i >= n1 || j >= n2 || k >= n3)
//         return 0;


//     int length = 0;

//     if(s1[i] == s2[j] && s2[j] == s3[k]){

//         length = 1 + findLength(n1, n2, n3, s1, s2, s3, i+1, j+1, k+1);
//     } 
//     else{

//         int x = findLength(n1, n2, n3, s1, s2, s3, i+1, j, k);
//         int y = findLength(n1, n2, n3, s1, s2, s3, i, j+1, k);
//         int z = findLength(n1, n2, n3, s1, s2, s3, i, j, k+1);

//         length = max({x, y, z});
//     }

//     return length;
// }

// int longestCommonSubsequence(string &s1, string &s2, string &s3){

//     int n1 = s1.size();
//     int n2 = s2.size();
//     int n3 = s3.size();

//     return findLength(n1, n2, n3, s1, s2, s3, 0, 0, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n1 * n2 * n3)  Space Complexity : O(n1 * n2 * n3) 
// int dp[20][20][20];

// int findLength(int n1, int n2, int n3, string &s1, string &s2, string &s3, int i, int j, int k){

//     // Base Case
//     if(i >= n1 || j >= n2 || k >= n3)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[i][j][k] != -1)
//         return dp[i][j][k];


//     int length = 0;

//     if(s1[i] == s2[j] && s2[j] == s3[k]){

//         length = 1 + findLength(n1, n2, n3, s1, s2, s3, i+1, j+1, k+1);
//     } 
//     else{

//         int x = findLength(n1, n2, n3, s1, s2, s3, i+1, j, k);
//         int y = findLength(n1, n2, n3, s1, s2, s3, i, j+1, k);
//         int z = findLength(n1, n2, n3, s1, s2, s3, i, j, k+1);

//         length = max({x, y, z});
//     }

//     // Step 2 : Store in dp array
//     dp[i][j][k] = length;

//     return dp[i][j][k];
// }

// int longestCommonSubsequence(string &s1, string &s2, string &s3){

//     int n1 = s1.size();
//     int n2 = s2.size();
//     int n3 = s3.size();

//     // Step 1 : Create dp array
//     memset(dp, -1, sizeof(dp));

//     return findLength(n1, n2, n3, s1, s2, s3, 0, 0, 0);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n1 * n2 * n3)  Space Complexity : O(n1 * n2 * n3) 
// int longestCommonSubsequence(string &s1, string &s2, string &s3){

//     int n1 = s1.size();
//     int n2 = s2.size();
//     int n3 = s3.size();

//     // Step 1 : Create dp array
//     int dp[n1+1][n2+1][n3+1];
//     memset(dp, -1, sizeof(dp));

//     // Step 2 : Tabulation
//     for(int i=n1; i>=0; i--){

//         for(int j=n2; j>=0; j--){

//             for(int k=n3; k>=0; k--){

//                 if(i == n1 || j == n2 || k == n3){

//                     dp[i][j][k] = 0;
//                 }
//                 else{

//                     int length = 0;

//                     if(s1[i] == s2[j] && s2[j] == s3[k]){

//                         length = 1 + dp[i+1][j+1][k+1];
//                     } 
//                     else{

//                         int x = dp[i+1][j][k];
//                         int y = dp[i][j+1][k];
//                         int z = dp[i][j][k+1];

//                         length = max({x, y, z});
//                     }

//                     // Step 2 : Store in dp array
//                     dp[i][j][k] = length;
//                 }
//             }
//         }
//     }

//     return dp[0][0][0];
// }

// Method 3 : Space Optimisation
// Time Complexity : O(n1 * n2 * n3)  Space Complexity : O(2 * n2 * n3) 
int longestCommonSubsequence(string &s1, string &s2, string &s3){

    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();

    // Step 1 : Create dp array
    vector<vector<int>> prev(n2+1, vector<int> (n3+1, 0));
    vector<vector<int>> curr(n2+1, vector<int> (n3+1, 0));

    // Step 2 : Tabulation
    for(int i=n1-1; i>=0; i--){

        for(int j=n2-1; j>=0; j--){

            for(int k=n3-1; k>=0; k--){

                int length = 0;

                if(s1[i] == s2[j] && s2[j] == s3[k]){

                    length = 1 + prev[j+1][k+1];
                } 
                else{

                    int x = prev[j][k];
                    int y = curr[j+1][k];
                    int z = curr[j][k+1];

                    length = max({x, y, z});
                }

                // Step 2 : Store in dp array
                curr[j][k] = length;
            }
        }

        prev = curr;
    }

    return prev[0][0];
}

int main()
{
    cout << "Enter first string : ";
    string first;
    cin >> first;

    cout << "Enter second string : ";
    string second;
    cin >> second;

    cout << "Enter third string : ";
    string third;
    cin >> third;

    // Longest Common Subsequence
    int longest = longestCommonSubsequence(first, second, third);

    cout << "Longest Common Subsequence : " << longest;

    cout << endl;
    return 0;
}