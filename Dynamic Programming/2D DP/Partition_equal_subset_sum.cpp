#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(n + (2 ^ n))  Space Complexity : O(n)
// bool subsetWithSum(int n, vector<int> &nums, int ind, int target){

//     // Base Case
//     if(target == 0)
//         return true;

//     if(ind >= n || target < 0)
//         return false;

    
//     int include = subsetWithSum(n, nums, ind+1, target-nums[ind]);
//     int exclude = subsetWithSum(n, nums, ind+1, target);


//     return include || exclude;
// }

// bool equalSubsetSum(vector<int> &nums){

//     int n = nums.size();

//     // Find sum to get partition
//     int sum = 0;

//     for(int i=0; i<n; i++){

//         sum += nums[i];
//     }

//     // If sum is odd
//     if(sum & 1)   return false;


//     int target = sum >> 1;

//     return subsetWithSum(n, nums, 0, target);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * target)  Space Complexity : O(n * target)
// bool subsetWithSum(int n, vector<int> &nums, int ind, int target, vector<vector<int>> &dp){

//     // Base Case
//     if(target == 0)
//         return true;

//     if(ind >= n || target < 0)
//         return false;

//     // Step 3 : Already Exists
//     if(dp[ind][target] != -1)
//         return dp[ind][target];

    
//     int include = subsetWithSum(n, nums, ind+1, target-nums[ind], dp);
//     int exclude = subsetWithSum(n, nums, ind+1, target, dp);
    

//     // Step 2 : Store in dp array
//     dp[ind][target] = include || exclude;

//     return dp[ind][target];
// }

// bool equalSubsetSum(vector<int> &nums){

//     int n = nums.size();

//     // Find sum to get partition
//     int sum = 0;

//     for(int i=0; i<n; i++){

//         sum += nums[i];
//     }

//     // If sum is odd
//     if(sum & 1)   return false;


//     // Step 1 : Create dp array
//     int target = sum >> 1;
//     vector<vector<int>> dp(n, vector<int> (target+1, -1));


//     return subsetWithSum(n, nums, 0, target, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * target)  Space Complexity : O(n * target)
// bool equalSubsetSum(vector<int> &nums){

//     int n = nums.size();

//     // Find sum to get partition
//     int sum = 0;

//     for(int i=0; i<n; i++){

//         sum += nums[i];
//     }

//     // If sum is odd
//     if(sum & 1)   return false;


//     // Step 1 : Create dp array
//     int target = sum >> 1;
//     vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));


//     // Step 2 : Tabulation
//     for(int ind=n-1; ind>=0; ind--){

//         for(int j=0; j<=target; j++){

//             if(j == 0){

//                 dp[ind][j] = true;
//             }
//             else{

//                 int include = 0;
                
//                 if(j-nums[ind] >= 0)
//                     include = dp[ind+1][j-nums[ind]];
                
//                 int exclude = dp[ind+1][j];
                

//                 // Step 2 : Store in dp array
//                 dp[ind][j] = include || exclude;
//             }

//         }
//     }

//     return dp[0][target];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * target)  Space Complexity : O(target)
bool equalSubsetSum(vector<int> &nums){

    int n = nums.size();

    // Find sum to get partition
    int sum = 0;

    for(int i=0; i<n; i++){

        sum += nums[i];
    }

    // If sum is odd
    if(sum & 1)   return false;


    // Step 1 : Create dp array
    int target = sum >> 1;
    vector<bool> dp(target+1, false);


    // Step 2 : Tabulation
    for(int ind=n-1; ind>=0; ind--){

        for(int j=target; j>=0; j--){

            if(j == 0){

                dp[j] = true;
            }
            else{

                int include = 0;
                
                if(j-nums[ind] >= 0)
                    include = dp[j-nums[ind]];
                
                int exclude = dp[j];
                

                // Step 2 : Store in dp array
                dp[j] = include || exclude;
            }

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
    vector <int> nums(size);

    for(int i=0; i<size; i++){

        cin >> nums[i];
    }

    // Partition Equal Subset Sum
    int equal = equalSubsetSum(nums);

    if(equal){

        cout << "Partition is possible !!";
    }
    else{

        cout << "Partition is not possible !!";
    }


    cout << endl;
    return 0;
}