#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ (min(n1, n2)))  Space Complexity : O(min(n1, n2))
// bool findMatch(int n1, int n2, string &str, string &pat, int i, int j){

//     // Base Case
//     if(i == n1 && j == n2)
//         return true;

//     if(i == n1 && j < n2){

//         for(int k=j; k<n2; k++){

//             if(pat[k] != '*')
//                 return false;
//         }

//         return true;
//     }

//     if(i >= n1 || j >= n2)
//         return false;


//     // Calls for different cases
//     bool match = false;
    
//     if(pat[j] == '?' || pat[j] == str[i]){

//         match = match || findMatch(n1, n2, str, pat, i+1, j+1);
//     }
//     else if(pat[j] == '*'){

//         match = match || findMatch(n1, n2, str, pat, i+1, j);
//         match = match || findMatch(n1, n2, str, pat, i, j+1);
//     }
//     else{

//         return false;
//     }

//     return match;
// }

// bool wildcardMatching(string &str, string &pat){

//     int n1 = str.size();
//     int n2 = pat.size();

//     return findMatch(n1, n2, str, pat, 0, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n1 * n2)  Space Complexity : O(n1 * n2)
// bool findMatch(int n1, int n2, string &str, string &pat, int i, int j, vector<vector<int>> &dp){

//     // Base Case
//     if(i == n1 && j == n2)
//         return true;

//     if(i == n1 && j < n2){

//         for(int k=j; k<n2; k++){

//             if(pat[k] != '*')
//                 return false;
//         }

//         return true;
//     }

//     if(i >= n1 || j >= n2)
//         return false;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     // Calls for different cases
//     bool match = false;
    
//     if(pat[j] == '?' || pat[j] == str[i]){

//         match = match || findMatch(n1, n2, str, pat, i+1, j+1, dp);
//     }
//     else if(pat[j] == '*'){

//         match = match || findMatch(n1, n2, str, pat, i+1, j, dp);
//         match = match || findMatch(n1, n2, str, pat, i, j+1, dp);
//     }
//     else{

//         return false;
//     }

//     // Step 2 : Store in dp array
//     dp[i][j] = match;


//     return dp[i][j];
// }

// bool wildcardMatching(string &str, string &pat){

//     int n1 = str.size();
//     int n2 = pat.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n1, vector<int> (n2, -1));

//     return findMatch(n1, n2, str, pat, 0, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n1 * n2)  Space Complexity : O(n1 * n2)
// bool wildcardMatching(string &str, string &pat){

//     int n1 = str.size();
//     int n2 = pat.size();

//     // Step 1 : Create dp array
//     vector<vector<bool>> dp(n1+1, vector<bool> (n2+1, false));


//     // Step 2 : Tabulation
//     for(int i=n1; i>=0; i--){

//         for(int j=n2; j>=0; j--){

//             if(i == n1 && j == n2){

//                 dp[i][j] = true;
//             }
//             else if(i == n1 && j < n2){

//                 dp[i][j] = true;

//                 for(int k=j; k<n2; k++){

//                     if(pat[k] != '*'){

//                         dp[i][j] = false;
//                         break;
//                     }
//                 }
//             }
//             else{

//                 bool match = false;
    
//                 if(pat[j] == '?' || pat[j] == str[i]){

//                     match = match || dp[i+1][j+1];
//                 }
//                 else if(pat[j] == '*'){

//                     match = match || dp[i+1][j];
//                     match = match || dp[i][j+1];
//                 }
//                 else{

//                     match = false;
//                 }

//                 dp[i][j] = match;
//             }
//         }
//     }

//     return dp[0][0];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n1 * n2)  Space Complexity : O(2 * n2)
bool wildcardMatching(string &str, string &pat){

    int n1 = str.size();
    int n2 = pat.size();

    // Step 1 : Create dp array
    vector<bool> prev(n2+1, false);
    vector<bool> curr(n2+1, false);


    // Step 2 : Tabulation
    for(int i=n1; i>=0; i--){

        for(int j=n2; j>=0; j--){

            if(i == n1 && j == n2){

                curr[j] = true;
            }
            else if(i == n1 && j < n2){

                curr[j] = true;

                for(int k=j; k<n2; k++){

                    if(pat[k] != '*'){

                        curr[j] = false;
                        break;
                    }
                }
            }
            else{

                bool match = false;
    
                if(pat[j] == '?' || pat[j] == str[i]){

                    match = match || prev[j+1];
                }
                else if(pat[j] == '*'){

                    match = match || prev[j];
                    match = match || curr[j+1];
                }
                else{

                    match = false;
                }

                curr[j] = match;
            }
        }

        prev = curr;
    }

    return prev[0];
}

int main()
{
    cout << "Enter input string : ";
    string str;
    cin >> str;

    cout << "Enter pattern string : ";
    string pat;
    cin >> pat;

    // Wildcard Matching
    bool match = wildcardMatching(str, pat);

    if(match){

        cout << "Match found !!";
    }
    else{

        cout << "Match not found !!";
    }


    cout << endl;
    return 0;
}