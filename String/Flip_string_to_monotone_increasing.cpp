#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Using Dynamic Programming
// Time Complexity : O(2 ^ n)  Space Complexity : O(n)
// int findCount(int n, string &str, char prev, int ind){

//     // Base Case
//     if(ind >= n)
//         return 0;


//     // Previous is '0' [we can flip or no change at all]
//     int first = INT_MAX;
//     int second = INT_MAX;

//     if(prev == '0'){

//         // Current is '0'
//         if(str[ind] == '0'){

//             first = findCount(n, str, '0', ind+1);
//             second = 1 + findCount(n, str, '1', ind+1);
//         }
//         else{

//             first = findCount(n, str, '1', ind+1);
//             second = 1 + findCount(n, str, '0', ind+1);
//         }
//     }
//     // Current is '1'
//     else{

//         if(str[ind] == '0'){

//             first = 1 + findCount(n, str, '1', ind+1);
//         }
//         else{

//             second = findCount(n, str, '1', ind+1);
//         }
//     }

//     return min(first, second);
// }

// int findFlipsCount(string &str){

//     int n = str.size();

//     return findCount(n, str, '0', 0);
// }

// Method 2 : Using Dynamic Programming & Memoisation
// Time Complexity : O(2 * n)  Space Complexity : O(2 * n)
// int findCount(int n, string &str, char prev, int ind, vector<vector<int>> &dp){

//     // Base Case
//     if(ind >= n)
//         return 0;

//     if(dp[prev-'0'][ind] != -1)
//         return dp[prev-'0'][ind];

    
//     int first = INT_MAX;
//     int second = INT_MAX;

//     // Previous is '0' [we can flip or no change at all]
//     if(prev == '0'){

//         // Current is '0'
//         if(str[ind] == '0'){

//             first = findCount(n, str, '0', ind+1, dp);
//             second = 1 + findCount(n, str, '1', ind+1, dp);
//         }
//         else{

//             first = findCount(n, str, '1', ind+1, dp);
//             second = 1 + findCount(n, str, '0', ind+1, dp);
//         }
//     }
//     // Previous is '1' [we can flip or no change at all]
//     else{

//         if(str[ind] == '0'){

//             first = 1 + findCount(n, str, '1', ind+1, dp);
//         }
//         else{

//             second = findCount(n, str, '1', ind+1, dp);
//         }
//     }

//     return dp[prev-'0'][ind] = min(first, second);
// }

// int findFlipsCount(string &str){

//     int n = str.size();

//     vector<vector<int>> dp(2, vector<int> (n, -1));

//     return findCount(n, str, '0', 0, dp);
// }

// Method 3 : Using Dynamic Programming & Tabulation
// Time Complexity : O(2 * n)  Space Complexity : O(2 * n)
// int findFlipsCount(string &str){

//     int n = str.size();

//     vector< vector<int> > dp(n+1, vector<int> (2, 0));

//     for(int ind=n-1; ind>=0; ind--){

//         for(int prev=0; prev<2; prev++){

//             int first = INT_MAX;
//             int second = INT_MAX;

//             if(prev == 0){

//                 // Current is '0'
//                 if(str[ind] == '0'){

//                     first = dp[ind+1][0];
//                     second = 1 + dp[ind+1][1];
//                 }
//                 else{

//                     first = dp[ind+1][1];
//                     second = 1 + dp[ind+1][0];
//                 }
//             }
//             // Previous is '1' [we can flip or no change at all]
//             else{

//                 if(str[ind] == '0'){

//                     first = 1 + dp[ind+1][1];
//                 }
//                 else{

//                     second = dp[ind+1][1];
//                 }
//             }

//             dp[ind][prev] = min(first, second);
//         }
//     }

//     return min(dp[0][0], dp[0][1]);
// }

// Method 4 : Space Optimisation - 1
// Time Complexity : O(2 * n)  Space Complexity : O(2 * 2)
// int findFlipsCount(string &str){

//     int n = str.size();

//     vector<int> p(2, 0);
//     vector<int> c(2, 0);

//     for(int ind=n-1; ind>=0; ind--){

//         for(int prev=0; prev<2; prev++){

//             int first = INT_MAX;
//             int second = INT_MAX;

//             if(prev == 0){

//                 // Current is '0'
//                 if(str[ind] == '0'){

//                     first = p[0];
//                     second = 1 + p[1];
//                 }
//                 else{

//                     first = p[1];
//                     second = 1 + p[0];
//                 }
//             }
//             // Previous is '1' [we can flip or no change at all]
//             else{

//                 if(str[ind] == '0'){

//                     first = 1 + p[1];
//                 }
//                 else{

//                     second = p[1];
//                 }
//             }

//             c[prev] = min(first, second);
//         }

//         p = c;
//     }

//     return min(p[0], p[1]);
// }

// Method 5 : Space Optimisation - 2
// Time Complexity : O(n)  Space Complexity : O(1)
int findFlipsCount(string &str){

    int n = str.size();

    int flip = 0;
    int ones = 0;

    for(int i=0; i<n; i++){

        if(str[i] == '1'){

            ones++;
        }
        else{

            flip++;
        }

        flip = min(ones, flip);
    }

    return flip;
}

int main()
{
    cout << "Enter Input String : ";
    string str;
    cin >> str;

    // Count Flips
    int count = findFlipsCount(str);

    cout << "Flips Count : " << count;


    cout << endl;
    return 0;
}