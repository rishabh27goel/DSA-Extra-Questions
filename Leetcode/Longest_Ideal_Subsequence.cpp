#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int result = 0;
        vector<int> dp(26, 0);

        for(int i=0; i<n; i++){

            int idx = (s[i]-'a');
            int best = 0;

            for(int j=0; j<26; j++){
                if(abs(idx - j) <= k){
                    best = max(best, dp[j]);
                }
            }

            dp[idx] = max(dp[idx], best + 1);
            result = max(result, dp[idx]);
        }

        return result;
    }
};