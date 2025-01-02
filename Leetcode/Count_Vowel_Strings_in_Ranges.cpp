#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;

        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = words.size();
        int q = queries.size();

        vector<int> validCount;
        int count = 0;

        for(int j = 0; j < n; j++) {
            int m = words[j].size();
            bool valid = false;

            if(isVowel(words[j][0]) && isVowel(words[j][m-1])) {
                valid = true;
            }

            count += valid;
            validCount.push_back(count);
        }

        vector<int> queryResult;
        for(int j = 0; j < queries.size(); j++) {
            int l = queries[j][0];
            int r = queries[j][1];

            queryResult.push_back(validCount[r] - (l - 1 >= 0 ? validCount[l-1] : 0));
        }

        return queryResult;
    }
};