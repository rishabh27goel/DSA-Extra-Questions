#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1e6 + 1;
int mod = 1e9 + 7;

int dp[MAX];

int findWays(int n) {
    // Base case
    if(n == 0)  return 1;

    if(dp[n] != -1)
        return dp[n];

    long totalWays = 0;
    for(int j = 1; j <= 6 && n - j >= 0; j++) {
        long ways = findWays(n - j);
        totalWays = (totalWays + ways) % mod;
    }

    return dp[n] = totalWays;
}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    int ways = findWays(n);
    cout << ways;

    return 0;
}