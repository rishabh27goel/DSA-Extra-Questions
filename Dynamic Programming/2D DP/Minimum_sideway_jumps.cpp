#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ n)  Space Complexity : O(n)
// int findJumps(int n, vector<int> &obs, int lane, int point){

//     // Base Case
//     if(point >= n-1)
//         return 0;


//     int sideways = 0;

//     // If we can not move forward [Move Sideways]
//     if(obs[point+1] == lane){

//         // If current point is 0 [No Obstacles]
//         if(obs[point] == 0){

//             int x = -1, y = -1;
            
//             for(int k=1; k<=3; k++){

//                 if(lane == k)   continue;

//                 if(x == -1)
//                     x = k;
//                 else if(y == -1)
//                     y = k;
//             }

//             int first = 1 + findJumps(n, obs, x, point);
//             int second = 1 + findJumps(n, obs, y, point);

//             sideways = min(first, second);
//         }
//         else{

//             sideways = 1 + findJumps(n, obs, 1 ^ 2 ^ 3 ^ (obs[point] ^ obs[point+1]), point);
//         }
//     }
//     else{

//         sideways = findJumps(n, obs, lane, point+1);
//     }


//     return sideways;
// }

// int findSidewayJumps(vector<int> &nums){

//     int n = nums.size();

//     return findJumps(n, nums, 2, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(4 * n)  Space Complexity : O(4 * n)
// int findJumps(int n, vector<int> &obs, int lane, int point, vector<vector<int>> &dp){

//     // Base Case
//     if(point >= n-1)
//         return 0;

//     // Step 3 : Already Exists 
//     if(dp[lane][point] != -1)
//         return dp[lane][point];


//     int sideways = 0;

//     // If we can not move forward [Move Sideways]
//     if(obs[point+1] == lane){

//         // If current point is 0 [No Obstacles]
//         if(obs[point] == 0){

//             int x = -1, y = -1;
            
//             for(int k=1; k<=3; k++){

//                 if(lane == k)   continue;

//                 if(x == -1)
//                     x = k;
//                 else if(y == -1)
//                     y = k;
//             }

//             int first = 1 + findJumps(n, obs, x, point, dp);
//             int second = 1 + findJumps(n, obs, y, point, dp);

//             sideways = min(first, second);
//         }
//         else{

//             sideways = 1 + findJumps(n, obs, (1 ^ 2 ^ 3) ^ (obs[point] ^ obs[point+1]), point, dp);
//         }
//     }
//     else{

//         sideways = findJumps(n, obs, lane, point+1, dp);
//     }

//     // Step 2 : Store in dp array
//     dp[lane][point] = sideways;


//     return dp[lane][point];
// }

// int findSidewayJumps(vector<int> &nums){

//     int n = nums.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(4, vector<int> (n, -1));

//     return findJumps(n, nums, 2, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(4 * n)  Space Complexity : O(4 * n)
// int findSidewayJumps(vector<int> &obs){

//     int n = obs.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(4, vector<int> (n, 0));
    

//     // Step 2 : Tabulation
//     for(int point=n-2; point>=0; point--){

//         int storeLane = -1;
//         int minSideways = INT_MAX;

//         for(int lane=1; lane<=3; lane++){

//             if(lane != obs[point] && lane != obs[point+1]){

//                 dp[lane][point] = dp[lane][point+1];
//                 minSideways = min(dp[lane][point], minSideways);
//             }

//             if(lane != obs[point] && lane == obs[point+1]){

//                 storeLane = lane;
//             } 
//         }

//         // If there is a lane which has obstacle
//         if(storeLane != -1)
//             dp[storeLane][point] = 1 + minSideways;
        
//     }

//     return dp[2][0];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(4 * n)  Space Complexity : O(4)
int findSidewayJumps(vector<int> &obs){

    int n = obs.size();

    // Step 1 : Create dp array
    vector<int> prev(4, 0);
    vector<int> curr(4, 0);
    

    // Step 2 : Tabulation
    for(int point=n-2; point>=0; point--){

        int storeLane = -1;
        int minSideways = INT_MAX;

        for(int lane=1; lane<=3; lane++){

            if(lane != obs[point] && lane != obs[point+1]){

                curr[lane] = prev[lane];
                minSideways = min(curr[lane], minSideways);
            }

            if(lane != obs[point] && lane == obs[point+1]){

                storeLane = lane;
            } 
        }

        // If there is a lane which has obstacle
        if(storeLane != -1)
            curr[storeLane] = 1 + minSideways;
        

        // Copy current in previous vector
        prev = curr;
    }

    return prev[2];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> nums(size);

    for(int i=0; i<size; i++){

        cin >> nums[i];
    }

    // Minimum Sideway Jumps
    int jumps = findSidewayJumps(nums);

    cout << "Minimum Sideway Jumps : " << jumps;

    cout << endl;
    return 0;
}