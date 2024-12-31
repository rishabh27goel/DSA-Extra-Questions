#include <iostream>
using namespace std;

class Solution {
public:
    int dp[100001];
    int mod = 1e9 + 7;

    int findTotal(int &zero, int &one, int &low, int &high, int length) {
        // Base Case
        if(length > high)
            return 0;

        if(dp[length] != -1)
            return dp[length];

        long total = 0;
        if(length >= low && length <= high)
            total++;

        total = (findTotal(zero, one, low, high, length + zero) + total);
        total = (findTotal(zero, one, low, high, length + one) + total);

        return dp[length] = total % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        memset(dp, -1, sizeof(dp));

        return findTotal(zero, one, low, high, 0);
    }
};