#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ n)  Space Complexity : O(n)
// int findLength(int n, vector<int> &arr, int curr, int prev){

//     // Base Case
//     if(curr == n)
//         return 0;


//     // If we are including current element
//     int include = 0;

//     if(prev == -1 || arr[curr] > arr[prev]){

//         include = 1 + findLength(n, arr, curr+1, curr);
//     }

//     // If we are excluding current element
//     int exclude = findLength(n, arr, curr+1, prev);


//     return max(include, exclude);
// }

// int longestIncreasingSubsequence(vector<int> &arr){

//     int n = arr.size();

//     return findLength(n, arr, 0, -1);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
// int findLength(int n, vector<int> &arr, int curr, int prev, vector<vector<int>> &dp){

//     // Base Case
//     if(curr == n)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[curr][prev+1] != -1)
//         return dp[curr][prev+1];

 
//     // If we are including current element
//     int include = 0;

//     if(prev == -1 || arr[curr] > arr[prev]){

//         include = 1 + findLength(n, arr, curr+1, curr, dp);
//     }

//     // If we are excluding current element
//     int exclude = findLength(n, arr, curr+1, prev, dp);


//     // Step 2 : Store in dp array
//     dp[curr][prev+1] = max(include, exclude);


//     return dp[curr][prev+1]; 
// }

// int longestIncreasingSubsequence(vector<int> &arr){

//     int n = arr.size();

//     // Step 1 : Create dp array [We will take prev + 1 so size should be n+1]
//     vector<vector<int>> dp(n, vector<int> (n+1, -1));

//     return findLength(n, arr, 0, -1, dp);
// }

// Method 3 : Dynamic Programming & Tabulation 
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
// int longestIncreasingSubsequence(vector<int> &arr){

//     int n = arr.size();

//     // Step 1 : Create dp array [We will take prev + 1 so size should be n+1]
//     vector<vector<int>> dp(n+1, vector<int> (n+2, 0));

//     // Step 2 : Tabulation
//     for(int curr=n-1; curr>=0; curr--){

//         for(int prev=n-1; prev>=-1; prev--){

//             int include = 0;

//             if(prev == -1 || arr[curr] > arr[prev]){

//                 include = 1 + dp[curr+1][curr+1];
//             }

//             // If we are excluding current element
//             int exclude = dp[curr+1][prev+1];


//             // Step 2 : Store in dp array
//             dp[curr][prev+1] = max(include, exclude);
 
//         }
//     }

//     return dp[0][0];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * n)  Space Complexity : O(2 * n)
// int longestIncreasingSubsequence(vector<int> &arr){

//     int n = arr.size();

//     // Step 1 : Create dp array [We will take prev + 1 so size should be n+1]
//     vector<int> currDp(n+2, 0);
//     vector<int> prevDp(n+2, 0);

//     // Step 2 : Tabulation
//     for(int curr=n-1; curr>=0; curr--){

//         for(int prev=n-1; prev>=-1; prev--){

//             int include = 0;

//             if(prev == -1 || arr[curr] > arr[prev]){

//                 include = 1 + prevDp[curr+1];
//             }

//             // If we are excluding current element
//             int exclude = prevDp[prev+1];


//             // Step 2 : Store in dp array
//             currDp[prev+1] = max(include, exclude);
 
//         }

//         prevDp = currDp;
//     }

//     return prevDp[0];
// }

// Method 5 : Using Binary Search
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
int longestIncreasingSubsequence(vector<int> &arr){

    int n = arr.size();

    // Storing elements in sorted order to apply Binary Search
    vector<int> sorted;

    for(int k=0; k<arr.size(); k++){

        // Binary Search
        int i = 0;
        int j = sorted.size()-1;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(arr[k] > sorted[mid]){

                i = mid + 1;
            }
            else{

                j = mid - 1;
            }
        }

        if(i < sorted.size()){

            sorted[i] = arr[k];
        }
        else{

            sorted.push_back(arr[k]);
        }
    }

    return sorted.size();
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    // Input : 10 9 2 5 3 7 101 18
    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }   
 
    // Longest Increasing Subsequence
    int longest = longestIncreasingSubsequence(arr);

    cout << "Longest Increasing Subsequence : " << longest;

    cout << endl;
    return 0;
}