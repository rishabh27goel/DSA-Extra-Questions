#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = strs.size();

        unordered_map<string, vector<string>> mp;

        for(int i=0; i<n; i++){
            
            int charCount[26] = {0};
            
            for(int j=0; j<strs[i].size(); j++){

                charCount[strs[i][j]-'a']++;
            }

            string hash = "";

            for(int j=0; j<26; j++){

                if(charCount[j] != 0){
                    hash.push_back((char) (j + 'a'));
                    hash += to_string(charCount[j]);
                }
            }

            mp[hash].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){

            result.push_back(itr->second);
        }

        return result;
    }
};