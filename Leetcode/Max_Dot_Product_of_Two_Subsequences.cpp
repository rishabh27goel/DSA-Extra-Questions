#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // int findMaxProduct(int n1, int n2, vector<int> &nums1, vector<int> &nums2, int idx1, int idx2, vector<vector<int>> &dp){

    //     // Base Case
    //     if(idx1 == n1 || idx2 == n2)
    //         return INT_MIN;
    
    //     if(dp[idx1][idx2] != INT_MIN)
    //         return dp[idx1][idx2];

    //     int call1 = findMaxProduct(n1, n2, nums1, nums2, idx1+1, idx2+1, dp);

    //     // Tricky part 
    //     // If call is not possible further
    //     if(call1 == INT_MIN){
        
    //         call1 = (nums1[idx1] * nums2[idx2]);
    //     }
    //     else {

    //         int product = (nums1[idx1] * nums2[idx2]);
    //         call1 = max(call1, max(product, call1 + product));
    //     }

    //     int call2 = findMaxProduct(n1, n2, nums1, nums2, idx1, idx2+1, dp);
    //     int call3 = findMaxProduct(n1, n2, nums1, nums2, idx1+1, idx2, dp);


    //     return dp[idx1][idx2] = max(call1, max(call2, call3));
    // }

    // int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
    //     int n1 = nums1.size();
    //     int n2 = nums2.size();

    //     vector<vector<int>> dp(n1, vector<int> (n2, INT_MIN));

    //     return findMaxProduct(n1, n2, nums1, nums2, 0, 0, dp);
    // }

    // int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n1 = nums1.size();
    //     int n2 = nums2.size();

    //     vector<vector<int>> dp(n1+1, vector<int> (n2+1, INT_MIN));

    //     for(int i=n1-1; i>=0; i--){

    //         for(int j=n2-1; j>=0; j--){

    //             int call1 = dp[i+1][j+1];

    //             // Tricky part 
    //             // If call is not possible further
    //             if(call1 == INT_MIN){
                
    //                 call1 = (nums1[i] * nums2[j]);
    //             }
    //             else {

    //                 int product = (nums1[i] * nums2[j]);
    //                 call1 = max(call1, max(product, call1 + product));
    //             }

    //             int call2 = dp[i+1][j];
    //             int call3 = dp[i][j+1];


    //             dp[i][j] = max(call1, max(call2, call3));
    //         }
    //     }

    //     return dp[0][0];
    // }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n1 = nums1.size();
        int n2 = nums2.size();

        // vector<vector<int>> dp(n1+1, vector<int> (n2+1, INT_MIN));

        vector<int> prev(n2+1, INT_MIN);
        vector<int> curr(n2+1, INT_MIN);

        for(int i=n1-1; i>=0; i--){

            for(int j=n2-1; j>=0; j--){

                int call1 = prev[j+1];

                // Tricky part 
                // If call is not possible further
                if(call1 == INT_MIN){
                
                    call1 = (nums1[i] * nums2[j]);
                }
                else {

                    int product = (nums1[i] * nums2[j]);
                    call1 = max(call1, max(product, call1 + product));
                }

                int call2 = prev[j];
                int call3 = curr[j+1];


                curr[j] = max(call1, max(call2, call3));
            }

            prev = curr;
        }

        return prev[0];
    }
};