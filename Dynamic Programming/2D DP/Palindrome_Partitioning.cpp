#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(n * n * (2 ^ n))  Space Complexity : O(n)
// bool isPalindrome(string &str, int i, int j){

//     while(i <= j){

//         if(str[i] != str[j])
//             return false;

//         i++;
//         j--;
//     }

//     return true;
// }

// int findMinimumCuts(int n, string &str, int ind){

//     // Base Case
//     if(ind >= n)
//         return 0;


//     // Find Minimum Cuts
//     int minCuts = INT_MAX;

//     for(int i=ind; i<n; i++){

//         if(isPalindrome(str, ind, i)){

//             int cuts = 1 + findMinimumCuts(n, str, i+1);

//             minCuts = min(cuts, minCuts);
//         }
//     }

//     return minCuts;
// }

// int palindromicPartitioning(string str){

//     int n = str.size();

//     return findMinimumCuts(n, str, 0) - 1;
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * n * n)  Space Complexity : O(n)
// bool isPalindrome(string &str, int i, int j){

//     while(i <= j){

//         if(str[i] != str[j])
//             return false;

//         i++;
//         j--;
//     }

//     return true;
// }

// int findMinimumCuts(int n, string &str, int ind, vector<int> &dp){

//     // Base Case
//     if(ind >= n)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[ind] != -1)
//         return dp[ind];


//     // Find Minimum Cuts
//     int minCuts = INT_MAX;

//     for(int i=ind; i<n; i++){

//         if(isPalindrome(str, ind, i)){

//             int cuts = 1 + findMinimumCuts(n, str, i+1, dp);

//             minCuts = min(cuts, minCuts);
//         }
//     }

//     // Step 2 : Store in dp array
//     dp[ind] = minCuts;


//     return dp[ind];
// }

// int palindromicPartitioning(string str){

//     int n = str.size();

//     // Step 1 : Create dp array
//     vector<int> dp(n, -1);

//     return findMinimumCuts(n, str, 0, dp) - 1;
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * n * n)  Space Complexity : O(n)
// bool isPalindrome(string &str, int i, int j){

//     while(i <= j){

//         if(str[i] != str[j])
//             return false;

//         i++;
//         j--;
//     }

//     return true;
// }

// int palindromicPartitioning(string str){

//     int n = str.size();

//     // Step 1 : Create dp array
//     vector<int> dp(n+1, 0);


//     // Step 2 : Tabulation
//     for(int ind=n-1; ind>=0; ind--){

//         int minCuts = INT_MAX;

//         for(int i=ind; i<n; i++){

//             if(isPalindrome(str, ind, i)){

//                 int cuts = 1 + dp[i+1];

//                 minCuts = min(cuts, minCuts);
//             }
//         }

//         dp[ind] = minCuts;
//     }   


//     return dp[0] - 1;
// }

// Method 4 : Time Optimisation [ Storing Palindromes in String ]
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
int palindromicPartitioning(string str){

    int n = str.size();

    // Storing Palindrome Indexes
    vector<vector<bool>> palindrome(n, vector<bool> (n, false));

    for(int i=0; i<n; i++){

        int l = i;
        int r = i;

        while(l >= 0 && r < n){

            // If palindrome exists with middle ith index
            if(str[l] == str[r])
                palindrome[l][r] = true;
            else
                break;

            l--;
            r++;
        }
    }
    
    for(int i=0; i<n-1; i++){

        int l = i;
        int r = i+1;

        while(l >= 0 && r < n){

            // If palindrome exists with middle ith index
            if(str[l] == str[r])
                palindrome[l][r] = true;
            else
                break;

            l--;
            r++;
        }
    }


    // Step 1 : Create dp array
    vector<int> dp(n+1, 0);


    // Step 2 : Tabulation
    for(int ind=n-1; ind>=0; ind--){

        int minCuts = INT_MAX;

        for(int i=ind; i<n; i++){

            if(palindrome[ind][i]){

                int cuts = 1 + dp[i+1];

                minCuts = min(cuts, minCuts);
            }
        }

        dp[ind] = minCuts;
    }   


    return dp[0] - 1;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    // Palindromic Partitioning
    int cuts = palindromicPartitioning(input);

    cout << "Minimum Partition : " << cuts;


    cout << endl;
    return 0;
}