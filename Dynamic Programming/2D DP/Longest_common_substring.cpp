#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ (min(n, m)))  Space Complexity : O(min(n, m))
// int findSubstring(int n, int m, string &s1, string &s2, int i, int j, int &maxLen){

//     // Base Case
//     if(i >= n || j >= m)
//         return 0;


//     int equal = 0;

//     if(s1[i] == s2[j]){

//         equal = 1 + findSubstring(n, m, s1, s2, i+1, j+1, maxLen);
//     }
    
//     int first = findSubstring(n, m, s1, s2, i+1, j, maxLen);
//     int second = findSubstring(n, m, s1, s2, i, j+1, maxLen);

//     // Update the max length
//     maxLen = max(equal, maxLen);

//     return equal;
// }

// int longestCommonSubstring(string &s1, string &s2){

//     int n = s1.size();
//     int m = s2.size();

//     int maxLen = 0;
//     int leng = findSubstring(n, m, s1, s2, 0, 0, maxLen);

//     return maxLen;
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
// int findSubstring(int n, int m, string &s1, string &s2, int i, int j, int &maxLen, vector<vector<int>> &dp){

//     // Base Case
//     if(i >= n || j >= m)
//         return 0;

//     // Step 3 : Already Exists 
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     int equal = 0;

//     if(s1[i] == s2[j]){

//         equal = 1 + findSubstring(n, m, s1, s2, i+1, j+1, maxLen, dp);
//     }
    
//     int first = findSubstring(n, m, s1, s2, i+1, j, maxLen, dp);
//     int second = findSubstring(n, m, s1, s2, i, j+1, maxLen, dp);

//     // Update the max length
//     maxLen = max(equal, maxLen);

//     // Step 2 : Store in dp array
//     dp[i][j] = equal;

//     return dp[i][j];
// }

// int longestCommonSubstring(string &s1, string &s2){

//     int n = s1.size();
//     int m = s2.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n, vector<int> (m, -1));

//     int maxLen = 0;
//     int leng = findSubstring(n, m, s1, s2, 0, 0, maxLen, dp);

//     return maxLen;
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
// int longestCommonSubstring(string &s1, string &s2){

//     int n = s1.size();
//     int m = s2.size();

//     // Step 1 : Create dp array
//     int maxLen = 0;
//     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

//     // Step 2 : Tabulation
//     for(int i=n-1; i>=0; i--){

//         for(int j=m-1; j>=0; j--){

//             int equal = 0;

//             if(s1[i] == s2[j]){

//                 equal = 1 + dp[i+1][j+1];
//             }
            
//             int first = dp[i+1][j];
//             int second = dp[i][j+1];

//             // Update the max length
//             maxLen = max(equal, maxLen);

//             // Step 2 : Store in dp array
//             dp[i][j] = equal;
//         }
//     }

//     return maxLen;
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * m)  Space Complexity : O(2 * m)
int longestCommonSubstring(string &s1, string &s2){

    int n = s1.size();
    int m = s2.size();

    // Step 1 : Create dp array
    int maxLen = 0;
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    // Step 2 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=m-1; j>=0; j--){

            int equal = 0;

            if(s1[i] == s2[j]){

                equal = 1 + prev[j+1];
            }
            
            int first = prev[j];
            int second = curr[j+1];

            // Update the max length
            maxLen = max(equal, maxLen);

            // Step 2 : Store in dp array
            curr[j] = equal;
        }

        prev = curr;
    }

    return maxLen;
}

int main()
{
    cout << "Enter first string : ";
    string s1;
    cin >> s1;

    cout << "Enter second string : ";
    string s2;
    cin >> s2;

    // Longest Common Substring
    int length = longestCommonSubstring(s1, s2);

    cout << "Longest Common Substring : " << length;

    cout << endl;
    return 0;
}