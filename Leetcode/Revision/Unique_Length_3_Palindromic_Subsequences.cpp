#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int countPalindromicSubsequence(string str) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = str.size();

    //     vector<vector<int>> prefixTrack;
    //     vector<int> prefix(26, 0);

    //     vector<int> firstIdx(26, -1);
    //     vector<int> secondIdx(26, -1);

    //     for(int j = 0; j < n; j++) {
    //         if(firstIdx[str[j]-'a'] == -1)
    //             firstIdx[str[j]-'a'] = j;

    //         secondIdx[str[j]-'a'] = j;

    //         prefix[str[j]-'a']++;
    //         prefixTrack.push_back(prefix);
    //     }

    //     int total = 0;
    //     for(int j = 0; j < 26; j++) {
    //         if(firstIdx[j] == secondIdx[j])  continue;

    //         int left = firstIdx[j];
    //         int right = secondIdx[j] - 1;

    //         int unique = 0;
    //         for(int k = 0; k < 26; k++) {
    //             if(prefixTrack[right][k] - prefixTrack[left][k] > 0) {
    //                 unique++;
    //             }
    //         }
    //         total += unique;
    //     }
    //     return total;
    // }

    int countPalindromicSubsequence(string str) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = str.size();

        vector<int> firstIdx(26, -1);
        vector<int> secondIdx(26, -1);

        for(int j = 0; j < n; j++) {
            if(firstIdx[str[j]-'a'] == -1)
                firstIdx[str[j]-'a'] = j;

            secondIdx[str[j]-'a'] = j;
        }

        int total = 0;
        for(int j = 0; j < 26; j++) {
            if(firstIdx[j] == secondIdx[j])  continue;

            int charCount[26] = {0};
            int left = firstIdx[j];
            int right = secondIdx[j];

            for(int k = left + 1; k < right; k++) {
                charCount[str[k]-'a']++;
            }

            int unique = 0;
            for(int k = 0; k < 26; k++) {
                if(charCount[k] > 0)
                    unique++;
            }
            total += unique;
        }

        return total;
    }
};