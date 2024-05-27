#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dp[100001][2][3];
    int mod = 1e9 + 7;

    int findRecords(int n, int abC, int conL){

        // Base Case
        if(abC > 1 || conL > 2)
            return 0;

        if(n == 0)
            return 1;

        if(dp[n][abC][conL] != -1)
            return dp[n][abC][conL];


        long pr = findRecords(n-1, abC, 0) % mod;
        long lt = findRecords(n-1, abC, conL + 1) % mod;
        long ab = findRecords(n-1, abC + 1, 0) % mod;

        return dp[n][abC][conL] = (pr + lt + ab) % mod;
    }


    int checkRecord(int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        memset(dp, -1, sizeof(dp));

        return findRecords(n, 0, 0);
    }
};