#include <iostream>
#include <vector>
using namespace std;

// int dp[101][101][27][101];    

class Solution {
public:

    // int findCompressedLength(int n, string &str, int idx, int k, char lastChar, int lastCharCount){

    //     // Base Case
    //     if(k < 0)
    //         return INT_MAX / 4;

    //     if(idx >= n)
    //         return 0;

    //     if(dp[idx][k][lastChar-'a'][lastCharCount] != -1)
    //         return dp[idx][k][lastChar-'a'][lastCharCount];

    //     // exclude the current char
    //     int exclude = findCompressedLength(n, str, idx+1, k-1, lastChar, lastCharCount);
    //     int include = 0;

    //     if(lastChar == str[idx]) {
    //         // Adding the length
    //         if(lastCharCount == 1 || lastCharCount == 9 || lastCharCount == 99)
    //             include = 1 + findCompressedLength(n, str, idx+1, k, lastChar, lastCharCount+1);
    //         else 
    //             include = findCompressedLength(n, str, idx+1, k, lastChar, lastCharCount+1);
    //     }   
    //     else {
    //         // Single Char 
    //         include = 1 + findCompressedLength(n, str, idx+1, k, str[idx], 1);
    //     }

    //     return dp[idx][k][lastChar-'a'][lastCharCount] = min(include, exclude);
    // }

    // int getLengthOfOptimalCompression(string s, int k) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = s.size();

    //     memset(dp, -1, sizeof(dp));

    //     return findCompressedLength(n, s, 0, k, 'z' + 1, 0);
    // }

    // unordered_map<int, int> dp;

    // int findCompressedLength(int n, string &str, int idx, int k, char lastChar, int lastCharCount){

    //     // Base Case
    //     if(k < 0)
    //         return INT_MAX / 4;

    //     if(idx >= n)
    //         return 0;

    //     int key = idx * (101 * 27 * 101) + k * (27 * 101) + (lastChar-'a') * 101 + lastCharCount;

    //     if(dp.find(key) != dp.end())
    //         return dp[key];

    //     // exclude the current char
    //     int exclude = findCompressedLength(n, str, idx+1, k-1, lastChar, lastCharCount);
    //     int include = 0;

    //     if(lastChar == str[idx]) {
    //         // Adding the length
    //         if(lastCharCount == 1 || lastCharCount == 9 || lastCharCount == 99)
    //             include = 1 + findCompressedLength(n, str, idx+1, k, lastChar, lastCharCount+1);
    //         else 
    //             include = findCompressedLength(n, str, idx+1, k, lastChar, lastCharCount+1);
    //     }   
    //     else {
    //         // Single Char 
    //         include = 1 + findCompressedLength(n, str, idx+1, k, str[idx], 1);
    //     }

    //     return dp[key] = min(include, exclude);
    // }

    // int getLengthOfOptimalCompression(string s, int k) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = s.size();

    //     return findCompressedLength(n, s, 0, k, 'z' + 1, 0);
    // }

    int dp[101][101];

    int findCompressedLength(int n, string &str, int idx, int k){

        // Base Case
        if(k < 0)
            return INT_MAX / 4;

        if(idx >= n || n - idx <= k)
            return 0;

        int &result = dp[idx][k];

        if(result != -1) 
            return result;

        result = INT_MAX;

        int charCount[26] = {0};
        int maxFreq = 0;

        for(int j=idx; j<n; j++){

            maxFreq = max(maxFreq, ++charCount[str[j]-'a']);

            int length = (maxFreq == 1 ? 1 : (maxFreq < 10 ? 2 : (maxFreq < 100 ? 3 : 4)));
            int call = length + findCompressedLength(n, str, j+1, k - ((j - idx + 1) - maxFreq));

            result = min(call, result);
        }

        return result;
    }

    int getLengthOfOptimalCompression(string s, int k) {

        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = s.size();

        memset(dp, -1, sizeof(dp));

        return findCompressedLength(n, s, 0, k);
    }
};