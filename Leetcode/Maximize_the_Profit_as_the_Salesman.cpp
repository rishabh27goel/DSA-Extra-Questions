#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dp[100001];

    int findMaxProfit(vector<vector<int>> &offers, int idx){

        // Base Case
        if(idx == offers.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];


        int exclude = findMaxProfit(offers, idx + 1);

        int target = offers[idx][1] + 1;
        int nextIdx = offers.size();
        
        int i = idx + 1;
        int j = offers.size()-1;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(offers[mid][0] >= target){

                nextIdx = mid;
                j = mid-1;
            }
            else{

                i = mid+1;
            }
        }

        int include = offers[idx][2] + findMaxProfit(offers, nextIdx);


        return dp[idx] = max(include, exclude); 
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        memset(dp, -1, sizeof(dp));

        sort(offers.begin(), offers.end());

        return findMaxProfit(offers, 0);            
    }
};