#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // The trick is to think about aaaaa
    // And how it has min turns as 1
    int dp[101][101];
    int findMinTurns(int n, string &str, int left, int right) {
        // Base Case
        if(left == right)
            return 1;

        if(dp[left][right] != -1)
            return dp[left][right];
            
        int minTurns = INT_MAX;
        for(int k = left + 1; k <= right; k++){
            int leftCall = findMinTurns(n, str, left, k - 1);
            int rightCall = findMinTurns(n, str, k, right);
        
            int totalTurns = leftCall + rightCall;
            if(str[left] == str[right])   totalTurns--;

            minTurns = min(minTurns, totalTurns);
        }

        return dp[left][right] = minTurns;
    }

    int strangePrinter(string str) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();
        memset(dp, -1, sizeof(dp));

        return findMinTurns(n, str, 0, n-1);
    }
};