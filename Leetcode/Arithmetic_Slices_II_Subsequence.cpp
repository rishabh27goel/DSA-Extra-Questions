#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int total = 0;
        vector<unordered_map<long long, int>> dp(n+1);

        for(int i=0; i<n; i++){

            for(int j=i-1; j>=0; j--){

                long long int diff = (long long) nums[i] - (long long) nums[j];
                int *curr = &dp[i][diff];
                *curr += 1;

                // Length >= 3 
                if(dp[j].find(diff) != dp[j].end()){

                    auto cnt = dp[j][diff];

                    total += cnt;
                    *curr += cnt;
                }
            }
        }

        return total;
    }
};