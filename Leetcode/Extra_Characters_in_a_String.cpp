#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    // Method 1 :
    // int dp[51];

    // int findMinChars(int n, string &str, unordered_set<string> &words, int idx){

    //     // Base Case
    //     if(idx == n)
    //         return 0;

    //     if(dp[idx] != -1)
    //         return dp[idx];


    //     int include = INT_MAX;
    //     string subStr = "";

    //     for(int j=idx; j<n; j++){

    //         subStr.push_back(str[j]);

    //         if(words.find(subStr) != words.end()){

    //             int call = findMinChars(n, str, words, j+1);

    //             include = min(include, call);
    //         }
    //     }

    //     int exclude = 1 + findMinChars(n, str, words, idx+1);


    //     return dp[idx] = min(include, exclude);
    // }

    // int minExtraChar(string str, vector<string>& dictionary) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = str.size();

    //     memset(dp, -1, sizeof(dp));

    //     unordered_set<string> words;

    //     for(int i=0; i<dictionary.size(); i++){

    //         words.insert(dictionary[i]);
    //     }

    //     return findMinChars(n, str, words, 0);
    // }


    // Method 2 :
    int dp[52];

    int minExtraChar(string str, vector<string>& dictionary) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        unordered_set<string> words;

        for(int i=0; i<dictionary.size(); i++){

            words.insert(dictionary[i]);
        }


        memset(dp, 0, sizeof(dp));

        for(int idx=n-1; idx>=0; idx--){

            int include = INT_MAX;
            string subStr = "";

            for(int j=idx; j<n; j++){

                subStr.push_back(str[j]);

                if(words.find(subStr) != words.end()){

                    int call = dp[j+1];

                    include = min(include, call);
                }
            }

            int exclude = 1 + dp[idx+1];


            dp[idx] = min(include, exclude);
        }


        return dp[0];
    }
};