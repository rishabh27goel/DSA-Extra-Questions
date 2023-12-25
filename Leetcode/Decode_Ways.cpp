#include <iostream>
using namespace std;

class Solution {
public:

    int dp[101];

    int findWays(int n, string &str, int idx){

        // Base Case
        if(idx >= n)
            return 1;

        // If current is 0 then we can't move forward
        if(str[idx] == '0')
            return 0;

        if(dp[idx] != -1)
            return dp[idx];


        int totalWays = 0;

        // Case 10 to 19
        if(idx + 1 < n && str[idx] == '1' && str[idx+1] >= '0' && str[idx+1] <= '9'){

            totalWays += findWays(n, str, idx+1);
            totalWays += findWays(n, str, idx+2);
        }
        // Case 20 to 26
        else if(idx + 1 < n && str[idx] == '2' && str[idx+1] >= '0' && str[idx+1] <= '6'){

            totalWays += findWays(n, str, idx+1);
            totalWays += findWays(n, str, idx+2);
        }
        else {

            totalWays += findWays(n, str, idx+1);
        }

        return dp[idx] = totalWays;
    }

    int numDecodings(string s) {
        
        int n = s.size();

        memset(dp, -1, sizeof(dp));

        return findWays(n, s, 0);
    }
};