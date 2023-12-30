#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = words.size();

        int charCount[26] = {0};

        for(int i=0; i<n; i++){

            for(int j=0; j<words[i].size(); j++){

                charCount[words[i][j]-'a']++;
            }   
        }

        for(int i=0; i<26; i++){

            if(charCount[i] == 0)
                continue;

            if(charCount[i] % n != 0)
                return false;
        }


        return true;
    }
};