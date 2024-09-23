#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // unordered_set<string> words;
    // int dp[51];

    // int findMinChars(int n, string &str, int idx) {
    //     // Base Case
    //     if(idx == n)
    //         return 0;

    //     if(dp[idx] != -1)
    //         return dp[idx];

    //     string prefix = "";
    //     int minChars = n;

    //     for(int j = idx; j < n; j++) {
    //         prefix.push_back(str[j]);

    //         if(words.find(prefix) != words.end()) {
    //             int include = findMinChars(n, str, j + 1);
    //             minChars = min(minChars, include);
    //         }
    //     }

    //     int exclude = 1 + findMinChars(n, str, idx + 1);
        
    //     return dp[idx] = min(minChars, exclude);
    // }

    // int minExtraChar(string str, vector<string>& dictionary) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = str.size();

    //     for(int j = 0; j < dictionary.size(); j++) {
    //         words.insert(dictionary[j]);
    //     }

    //     memset(dp, -1, sizeof(dp));
    //     return findMinChars(n, str, 0);
    // }

    int minExtraChar(string str, vector<string>& dictionary) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        unordered_set<string> words;
        int dp[51];
        memset(dp, 0, sizeof(dp));

        for(int j = 0; j < dictionary.size(); j++) {
            words.insert(dictionary[j]);
        }

        for(int idx = n-1; idx >= 0; idx--) {
            string prefix = "";
            int minChars = n;

            for(int j = idx; j < n; j++) {
                prefix.push_back(str[j]);

                if(words.find(prefix) != words.end()) {
                    int include = dp[j+1];
                    minChars = min(minChars, include);
                }
            }

            int exclude = 1 + dp[idx+1];
            dp[idx] = min(minChars, exclude);
        }
        
        return dp[0];
    }
};