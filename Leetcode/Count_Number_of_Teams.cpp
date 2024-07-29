#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time : O(n^3)  Space : O(1)
    // int numTeams(vector<int>& rating) {
        
    //     int n = rating.size();

    //     int result = 0;
    //     for(int i = 0; i < n; i++){
    //         for(int j = i + 1; j < n; j++){
    //             for(int k = j + 1; k < n; k++){
    //                 if(rating[i] < rating[j] && rating[j] < rating[k])
    //                     result++;

    //                 else if(rating[i] > rating[j] && rating[j] > rating[k])
    //                     result++;
    //             }
    //         }
    //     }

    //     return result;
    // }

    // int findIncreasingTeams(int n, vector<int> &rating, int currIdx, int teamSize, vector<vector<int>> &dp){
    //     // Base Case
    //     if(teamSize == 3)  return 1;
    //     if(currIdx >= n-1)  return 0; 
        
    //     if(dp[currIdx][teamSize] != -1)
    //         return dp[currIdx][teamSize];

    //     int totalTeams = 0;
    //     for(int j = currIdx + 1; j < n; j++){
    //         if(rating[j] > rating[currIdx]){
    //             totalTeams += findIncreasingTeams(n, rating, j, teamSize + 1, dp);
    //         }
    //     }

    //     return dp[currIdx][teamSize] = totalTeams;
    // }

    // int findDecreasingTeams(int n, vector<int> &rating, int currIdx, int teamSize, vector<vector<int>> &dp){
    //     // Base Case
    //     if(teamSize == 3)  return 1;
    //     if(currIdx >= n-1)  return 0; 

    //     if(dp[currIdx][teamSize] != -1)
    //         return dp[currIdx][teamSize];
        
    //     int totalTeams = 0;
    //     for(int j = currIdx + 1; j < n; j++){
    //         if(rating[j] < rating[currIdx]){
    //             totalTeams += findDecreasingTeams(n, rating, j, teamSize + 1, dp);
    //         }
    //     }

    //     return dp[currIdx][teamSize] = totalTeams;
    // }

    // Time : O(n^2)  Space : O(n)
    // int numTeams(vector<int>& rating) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = rating.size();

    //     vector<vector<int>> increasingDp(n, vector<int> (4, -1));
    //     vector<vector<int>> decreasingDp(n, vector<int> (4, -1));

    //     int totalTeams = 0;
    //     for(int i=0; i<n; i++){
    //         totalTeams += findIncreasingTeams(n, rating, i, 1, increasingDp);
    //         totalTeams += findDecreasingTeams(n, rating, i, 1, decreasingDp);
    //     }
        
    //     return totalTeams;
    // }

    // Time : O(n^2)  Space : O(1)
    // Taking middle element as fixed
    int numTeams(vector<int>& rating) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = rating.size();

        int totalTeams = 0;
        for(int middle = 0; middle < n; middle++){
            int leftSmaller = 0;
            int j = middle - 1;

            while(j >= 0){
                if(rating[j] < rating[middle])  leftSmaller++;
                j--;
            }

            int rightLarger = 0;
            j = middle + 1;

            while(j < n){
                if(rating[middle] < rating[j])  rightLarger++;
                j++;
            }

            totalTeams += (leftSmaller * rightLarger);

            int leftLarger = middle - leftSmaller;
            int rightSmaller = n - 1 - middle - rightLarger;

            totalTeams += (rightSmaller * leftLarger);
        }

        return totalTeams;
    }
};