#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(n * (2 ^ (n * n)))   Space Complexity : O(n)
// int findCost(vector<int> &cuts, int i, int j){

//     // Base Case
//     if(j - i <= 1)
//         return 0;


//     // Iterate all the indexes 
//     int minCost = INT_MAX;

//     for(int k=i+1; k<j; k++){

//         int cost = findCost(cuts, i, k) + (cuts[j] - cuts[i]) + findCost(cuts, k, j);

//         minCost = min(cost, minCost);
//     }


//     if(minCost == INT_MAX)
//         return 0;


//     return minCost;
// }

// int minimumCost(int length, vector<int> &cuts){

//     // Update the cuts
//     cuts.push_back(0);
//     cuts.push_back(length);

//     // Sort the cuts
//     sort(cuts.begin(), cuts.end());


//     int n = cuts.size();

//     return findCost(cuts, 0, n-1);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * n * n)   Space Complexity : O(n * n)
// int findCost(vector<int> &cuts, int i, int j,  vector<vector<int>> &dp){

//     // Base Case
//     if(j - i <= 1)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     // Iterate all the indexes 
//     int minCost = INT_MAX;

//     for(int k=i+1; k<j; k++){

//         int cost = findCost(cuts, i, k, dp) + (cuts[j] - cuts[i]) + findCost(cuts, k, j, dp);

//         minCost = min(cost, minCost);
//     }


//     // Step 2 : Store in dp array
//     if(minCost == INT_MAX)
//         return dp[i][j] = 0;


//     return dp[i][j] = minCost;
// }

// int minimumCost(int length, vector<int> &cuts){

//     // Update the cuts
//     cuts.push_back(0);
//     cuts.push_back(length);

//     // Sort the cuts
//     sort(cuts.begin(), cuts.end());


//     int n = cuts.size();

//     // Step 1 : Create dp array
//     vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

//     return findCost(cuts, 0, n-1, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * n * n)   Space Complexity : O(n * n)
int minimumCost(int length, vector<int> &cuts){

    // Update the cuts
    cuts.push_back(0);
    cuts.push_back(length);

    // Sort the cuts
    sort(cuts.begin(), cuts.end());


    int n = cuts.size();

    // Step 1 : Create dp array
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));


    // Step 2 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=i; j<n; j++){

            if(j - i <= 1){

                dp[i][j] = 0;
            }
            else{

                int minCost = INT_MAX;

                for(int k=i+1; k<j; k++){

                    int cost = dp[i][k] + (cuts[j] - cuts[i]) + dp[k][j];

                    minCost = min(cost, minCost);
                }


                if(minCost != INT_MAX)
                    dp[i][j] = minCost;
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
    cout << "Enter length : ";
    int length;
    cin >> length;
    
    cout << "Enter size : ";
    int size;
    cin >> size;


    cout << "Enter array : ";
    vector <int> cuts(size);

    for(int i=0; i<size; i++){

        cin >> cuts[i];
    }

    // Minimum Cost to Cut
    int cost = minimumCost(length, cuts);

    cout << "Minimum Cost : " << cost;


    cout << endl;
    return 0;
}