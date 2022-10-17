#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ n)  Space Complexity : O(n)
// int findMaxProfit(int n, vector<int> &prices, int canBuy, int ind){

//     // Base Case
//     if(ind >= n)
//         return 0;


//     // Buying Stock
//     int buy = 0;

//     if(canBuy == true){

//         int include = -prices[ind] + findMaxProfit(n, prices, false, ind+1);

//         int ignore = findMaxProfit(n, prices, canBuy, ind+1);

//         buy = max(include, ignore);
//     }


//     // Selling Stock
//     int sell = 0;

//     if(canBuy == false){

//         int include = prices[ind] + findMaxProfit(n, prices, true, ind+1);

//         int ignore = findMaxProfit(n, prices, canBuy, ind+1);

//         sell = max(include, ignore);
//     }


//     return max(buy, sell);
// }

// int findPrices(vector<int> &prices){

//     int n = prices.size();

//     return findMaxProfit(n, prices, true, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(2 * n)  Space Complexity : O(2 * n)
// int findMaxProfit(int n, vector<int> &prices, int canBuy, int ind, vector<vector<int>> &dp){

//     // Base Case
//     if(ind >= n)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[canBuy][ind] != -1)
//         return dp[canBuy][ind];


//     // Buying Stock
//     int buy = 0;

//     if(canBuy == true){

//         int include = -prices[ind] + findMaxProfit(n, prices, false, ind+1, dp);

//         int ignore = findMaxProfit(n, prices, canBuy, ind+1, dp);

//         buy = max(include, ignore);
//     }


//     // Selling Stock
//     int sell = 0;

//     if(canBuy == false){

//         int include = prices[ind] + findMaxProfit(n, prices, true, ind+1, dp);

//         int ignore = findMaxProfit(n, prices, canBuy, ind+1, dp);

//         sell = max(include, ignore);
//     }


//     // Step 2 : Store in dp array
//     dp[canBuy][ind] = max(buy, sell);


//     return dp[canBuy][ind];
// }

// int findPrices(vector<int> &prices){

//     int n = prices.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(2, vector<int> (n, -1));

//     return findMaxProfit(n, prices, true, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(2 * n)  Space Complexity : O(2 * n)
// int findPrices(vector<int> &prices){

//     int n = prices.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n+1, vector<int> (2, 0));


//     // Step 2 : Tabulation
//     for(int ind=n-1; ind>=0; ind--){

//         for(int canBuy=0; canBuy<=1; canBuy++){

//             // Buying Stock
//             int buy = 0;

//             if(canBuy == true){

//                 int include = -prices[ind] + dp[ind+1][false];

//                 int ignore = dp[ind+1][canBuy];

//                 buy = max(include, ignore);
//             }


//             // Selling Stock
//             int sell = 0;

//             if(canBuy == false){

//                 int include = prices[ind] + dp[ind+1][true];

//                 int ignore = dp[ind+1][canBuy];

//                 sell = max(include, ignore);
//             }

//             dp[ind][canBuy] = max(buy, sell);
//         }   
//     }


//     return dp[0][1];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(2 * n)  Space Complexity : O(2 * 2)
// int findPrices(vector<int> &prices){

//     int n = prices.size();

//     // Step 1 : Create dp array
//     vector<int> prev(2, 0);
//     vector<int> curr(2, 0);


//     // Step 2 : Tabulation
//     for(int ind=n-1; ind>=0; ind--){

//         for(int canBuy=0; canBuy<=1; canBuy++){

//             // Buying Stock
//             int buy = 0;

//             if(canBuy == true){

//                 int include = -prices[ind] + prev[false];

//                 int ignore = prev[canBuy];

//                 buy = max(include, ignore);
//             }


//             // Selling Stock
//             int sell = 0;

//             if(canBuy == false){

//                 int include = prices[ind] + prev[true];

//                 int ignore = prev[canBuy];

//                 sell = max(include, ignore);
//             }

//             curr[canBuy] = max(buy, sell);
//         }   

//         prev = curr;
//     }


//     return prev[1];
// }

// Method 5 : Space Optimisation - 2
// Time Complexity : O(n)  Space Complexity : O(1)
int findPrices(vector<int> &prices){

    int n = prices.size();

    int profit = 0;

    for(int i=0; i<n-1; i++){

        if(prices[i] < prices[i+1])
            profit += (prices[i+1] - prices[i]);
    }

    return profit;
} 

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> prices(size);

    for(int i=0; i<size; i++){

        cin >> prices[i];
    }

    // Best Time to Buy and Sell Stock II
    int profit = findPrices(prices);

    cout << "Maximum Profit : " << profit;
 

    cout << endl;
    return 0;
}