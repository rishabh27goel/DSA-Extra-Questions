#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ n)  Space Complexity : O(n)
// bool findSum(int n, vector<int> &nums, int ind, int target){

//     // Base Case
//     if(target == 0)
//         return true;
    
//     if(target < 0 || ind >= n)
//         return false;


//     // Include and Exclude elements
//     int include = findSum(n, nums, ind+1, target-nums[ind]);
//     int exclude = findSum(n, nums, ind+1, target);


//     return include || exclude;
// }

// bool subsetSum(vector<int> &nums, int target){

//     int n = nums.size();

//     return findSum(n, nums, 0, target);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * target)  Space Complexity : O(n * target)
// bool findSum(int n, vector<int> &nums, int ind, int target, vector<vector<int>> &dp){

//     // Base Case
//     if(target == 0)
//         return true;
    
//     if(target < 0 || ind >= n)
//         return false;

//     // Step 3 : Already Exists
//     if(dp[ind][target] != -1)
//         return dp[ind][target];


//     // Include and Exclude elements
//     int include = findSum(n, nums, ind+1, target-nums[ind], dp);
//     int exclude = findSum(n, nums, ind+1, target, dp);


//     // Step 2 : Store in dp array
//     dp[ind][target] = include || exclude;

//     return dp[ind][target];
// }

// bool subsetSum(vector<int> &nums, int target){

//     int n = nums.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n, vector<int> (target+1, -1));

//     return findSum(n, nums, 0, target, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * target)  Space Complexity : O(n * target)
// bool subsetSum(vector<int> &nums, int target){

//     int n = nums.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n+1, vector<int> (target+1, false));

//     // Step 2 : Tabulation
//     for(int i=0; i<=n; i++){

//         dp[i][0] = true;
//     }

//     for(int ind=n-1; ind>=0; ind--){

//         for(int j=1; j<=target; j++){

//             // Include and Exclude elements
//             int include = false;
            
//             if(j - nums[ind] >= 0)
//                 include = dp[ind+1][j-nums[ind]];
            
//             int exclude = dp[ind+1][j];


//             // Step 2 : Store in dp array
//             dp[ind][j] = include || exclude;
//         }
//     }

//     return dp[0][target];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * target)  Space Complexity : O(target)
bool subsetSum(vector<int> &nums, int target){

    int n = nums.size();

    // Step 1 : Create dp array
    vector<int> dp(target+1, false);

    // Base Case
    dp[0] = true;


    // Step 2 : Tabulation
    for(int ind=n-1; ind>=0; ind--){

        for(int j=target; j>=1; j--){

            // Include and Exclude elements
            int include = false;
            
            if(j - nums[ind] >= 0)
                include = dp[j-nums[ind]];
            
            int exclude = dp[j];


            // Step 2 : Store in dp array
            dp[j] = include || exclude;
        }
    }

    return dp[target];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter array : ";
    vector<int> nums(size);

    for(int i=0; i<size; i++){

        cin >> nums[i];
    }

    cout << "Enter target : ";
    int target;
    cin >> target;


    // Subset Sum Problem
    bool exists = subsetSum(nums, target);

    if(exists){

        cout << "Subset exists !!";
    }
    else{

        cout << "Subset doesn't exists !!";
    }

    cout << endl;
    return 0;
}