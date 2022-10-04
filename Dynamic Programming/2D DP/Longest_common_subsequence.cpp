#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ (n * m))  Space Complexity : O(n * m)
// int findLongestSubsequence(int n, int m, string &s1, string &s2, int i, int j){

//     // Base Case
//     if(i >= n || j >= m)
//         return 0;


//     int length = 0;

//     // If characters are equal
//     if(s1[i] == s2[j]){

//         length = 1 + findLongestSubsequence(n, m, s1, s2, i+1, j+1);
//     }    
//     else{

//         int first = findLongestSubsequence(n, m, s1, s2, i+1, j);
//         int second = findLongestSubsequence(n, m, s1, s2, i, j+1);

//         length = max(first, second);
//     }

//     return length;
// }

// int longestCommonSubsequence(string &s1, string &s2){

//     int n = s1.size();
//     int m = s2.size();

//     return findLongestSubsequence(n, m, s1, s2, 0, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
// int findLongestSubsequence(int n, int m, string &s1, string &s2, int i, int j, vector<vector<int>> &dp){

//     // Base Case
//     if(i >= n || j >= m)
//         return 0;

//     // Step 3 : Already Exists 
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     int length = 0;

//     // If characters are equal
//     if(s1[i] == s2[j]){

//         length = 1 + findLongestSubsequence(n, m, s1, s2, i+1, j+1, dp);
//     }    
//     else{

//         int first = findLongestSubsequence(n, m, s1, s2, i+1, j, dp);
//         int second = findLongestSubsequence(n, m, s1, s2, i, j+1, dp);

//         length = max(first, second);
//     }

//     // Step 2 : Store in dp array
//     dp[i][j] = length;


//     return dp[i][j];
// }

// int longestCommonSubsequence(string &s1, string &s2){

//     int n = s1.size();
//     int m = s2.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n, vector<int> (m, -1));

//     return findLongestSubsequence(n, m, s1, s2, 0, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
// int longestCommonSubsequence(string &s1, string &s2){

//     int n = s1.size();
//     int m = s2.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

//     // Step 2 : Tabulation
//     for(int i=n-1; i>=0; i--){

//         for(int j=m-1; j>=0; j--){

//             int length = 0;

//             // If characters are equal
//             if(s1[i] == s2[j]){

//                 length = 1 + dp[i+1][j+1];
//             }    
//             else{

//                 int first = dp[i+1][j];
//                 int second = dp[i][j+1];

//                 length = max(first, second);
//             }

//             // Step 2 : Store in dp array
//             dp[i][j] = length;
//         }
//     }

//     return dp[0][0];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * m)  Space Complexity : O(2 * m)
int longestCommonSubsequence(string &s1, string &s2){

    int n = s1.size();
    int m = s2.size();

    // Step 1 : Create dp array
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    // Step 2 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=m-1; j>=0; j--){

            int length = 0;

            // If characters are equal
            if(s1[i] == s2[j]){

                length = 1 + prev[j+1];
            }    
            else{

                int first = prev[j];
                int second = curr[j+1];

                length = max(first, second);
            }

            // Step 2 : Store in dp array
            curr[j] = length;
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

    // Longest Common Subsequence
    int longest = longestCommonSubsequence(s1, s2);

    cout << "Longest Common Subsequence : " << longest;


    cout << endl;
    return 0;
}