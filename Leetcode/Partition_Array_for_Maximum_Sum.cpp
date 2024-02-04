#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dp[502];

    // int findSum(int n, vector<int> &arr, int k, int idx){

    //     // Base Case
    //     if(idx >= n)
    //         return 0;

    //     if(dp[idx] != -1)
    //         return dp[idx];


    //     int result = 0;
    //     int maxVal = 0;

    //     for(int i = 0; i < k && i+idx < n; i++){

    //         maxVal = max(arr[idx+i], maxVal);

    //         int call = ((i + 1) * maxVal) + findSum(n, arr, k, idx+i+1);
    //         result = max(result, call);
    //     }

    //     return dp[idx] = result;
    // }

    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = arr.size();

    //     memset(dp, -1, sizeof(dp));

    //     return findSum(n, arr, k, 0);
    // }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        memset(dp, 0, sizeof(dp));

        for(int idx=n-1; idx>=0; idx--){

            int result = 0;
            int maxVal = 0;

            for(int i = 0; i < k && i+idx < n; i++){

                maxVal = max(arr[idx+i], maxVal);

                int call = ((i + 1) * maxVal) + dp[idx+i+1];
                result = max(result, call);
            }

            dp[idx] = result;
        }

        return dp[0];
    }
};