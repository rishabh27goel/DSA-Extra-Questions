#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(n * (2 ^ n))  Space Complexity : O(n)
// int findMaxCoins(int n, vector<int> &nums, int i, int j){

//     // Base Case
//     if(i > j)
//         return 0;


//     int maxCoins = 0;

//     for(int ind=i; ind<=j; ind++){

//         int left = 1;
//         int right = 1;

//         if(i-1 >= 0)   
//             left = nums[i-1];

//         if(j+1 < n)
//             right = nums[j+1];


//         int coins = findMaxCoins(n, nums, i, ind-1) + (left * nums[ind] * right) + findMaxCoins(n, nums, ind+1, j);
    
//         maxCoins = max(coins, maxCoins);
//     }

//     return maxCoins;
// }

// int burstBalloon(vector<int> &nums){

//     int n = nums.size();

//     return findMaxCoins(n, nums, 0, n-1);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
// int findMaxCoins(int n, vector<int> &nums, int i, int j, vector<vector<int>> &dp){

//     // Base Case
//     if(i > j)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     int maxCoins = 0;

//     for(int ind=i; ind<=j; ind++){

//         int left = 1;
//         int right = 1;

//         if(i-1 >= 0)   
//             left = nums[i-1];

//         if(j+1 < n)
//             right = nums[j+1];


//         int coins = findMaxCoins(n, nums, i, ind-1, dp) + (left * nums[ind] * right) + findMaxCoins(n, nums, ind+1, j, dp);
    
//         maxCoins = max(coins, maxCoins);
//     }


//     // Step 2 : Store in dp array
//     dp[i][j] = maxCoins;

 
//     return dp[i][j];
// }

// int burstBalloon(vector<int> &nums){

//     int n = nums.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n, vector<int> (n, -1));

//     return findMaxCoins(n, nums, 0, n-1, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
int burstBalloon(vector<int> &nums){

    int n = nums.size();

    // Step 1 : Create dp array
    vector<vector<int>> dp(n, vector<int> (n, -1));


    // Step 2 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=i; j<n; j++){

            int maxCoins = 0;

            for(int ind=i; ind<=j; ind++){

                int left = 1;
                int right = 1;

                if(i-1 >= 0)   
                    left = nums[i-1];

                if(j+1 < n)
                    right = nums[j+1];


                int leftSide = 0;

                if(ind-1 >=0)
                    leftSide = dp[i][ind-1];


                int coins = leftSide + (left * nums[ind] * right) + dp[ind+1][j];
            
                maxCoins = max(coins, maxCoins);
            }

            dp[i][j] = maxCoins;
        }
    }

    return dp[0][n-1];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;
    
    vector<int> nums(size);
    cout << "Enter array : ";

    for(int i=0; i<size; i++){

        cin >> nums[i];
    }

    // Burst Balloon
    int coins = burstBalloon(nums);

    cout << "Maximum Coins : " << coins;


    cout << endl;
    return 0;
}