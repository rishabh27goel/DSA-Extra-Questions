#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(n * (n ^ n))  Space Complexity : O(n)
// int findJumps(int n, vector<int> &arr, int ind){

//     // Base Case
//     if(ind >= n)
//         return -1;

//     if(ind == n-1)
//         return 0;


//     // Find minimum jumps
//     int minJumps = INT_MAX;

//     for(int i=1; i<=arr[ind]; i++){

//         if(ind + i >= n)  break;

//         int jump = findJumps(n, arr, ind+i);

//         if(jump >= 0)
//             minJumps = min(minJumps, jump+1);
//     }

//     if(minJumps == INT_MAX)
//         return -1;

//     return minJumps;
// }

// int minimumJumps(vector<int> &arr){

//     int n = arr.size();

//     return findJumps(n, arr, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * n)  Space Complexity : O(n)
// int findJumps(int n, vector<int> &arr, int ind, vector<int> &dp){

//     // Base Case
//     if(ind >= n)
//         return -1;

//     if(ind == n-1)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[ind] != -1)
//         return dp[ind];

//     // Find minimum jumps
//     int minJumps = INT_MAX;

//     for(int i=1; i<=arr[ind]; i++){

//         if(ind + i >= n)  break;

//         int jump = findJumps(n, arr, ind+i, dp);

//         if(jump >= 0)
//             minJumps = min(minJumps, jump+1);
//     }

//     if(minJumps == INT_MAX)
//         return -1;

//     // Step 2 : Store in dp array
//     dp[ind] = minJumps;

//     return dp[ind];
// }

// int minimumJumps(vector<int> &arr){

//     int n = arr.size();

//     // Step 1 : Create dp array
//     vector <int> dp(n, -1);

//     return findJumps(n, arr, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * n)  Space Complexity : O(n)
 int minimumJumps(vector<int> &arr){

    int n = arr.size();

    // Step 1 : Create dp array
    vector <int> dp(n, -1);

    // Base Case
    dp[n-1] = 0;

    // Step 2 : Tabulation
    for(int i=n-2; i>=0; i--){

        int minJumps = INT_MAX;

        for(int j=1; j<=arr[i]; j++){

            if(i + j >= n)  break;

            int jump = dp[i + j];

            if(jump >= 0)
                minJumps = min(minJumps, jump+1);
        }

        if(minJumps == INT_MAX)
            minJumps = -1;

        dp[i] = minJumps;
    }

    return dp[0];
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Input :  1 3 5 8 9 2 6 7 6 8 9
    vector <int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    // Minimum number of jumps
    int jumps = minimumJumps(arr);
    
    cout << "Minimum Jumps : " << jumps;

    cout << endl;
    return 0;
}