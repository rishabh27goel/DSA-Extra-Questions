#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Method 2 :
    // Longest Incresing Subseq logic is required

    // Method 1 : 
    bool isValid(vector<string> &words, int i, int j){

        int x = 0;
        int y = 0;

        while(y < words[i].size()){

            if(words[i][y] == words[j][x])
                x++;

            y++;
        }

        return x == words[j].size();
    }

    int longestStrChain(vector<string>& words) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = words.size();

        // Sort by word length
        sort(words.begin(), words.end(), [&](const string &s1, const string &s2){

            return s1.size() < s2.size();
        });


        int result = 0;
        int dp[n];

        memset(dp, 0, 4 * n);

        for(int i=n-1; i>=0; i--){

            int j = i-1;

            while(j >= 0 && words[j].size() == words[i].size())
                j--;

            
            while(j >= 0 && words[j].size() == words[i].size() - 1){

                if(isValid(words, i, j)){

                    dp[j] = max(dp[j], dp[i] + 1);

                    result = max(dp[j], result);
                }

                j--;
            }
        }

        return result + 1;
    }
};