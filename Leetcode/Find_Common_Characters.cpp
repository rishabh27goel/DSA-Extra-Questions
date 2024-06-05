#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL); 

        int n = words.size();

        vector<vector<int>> countChar(n, vector<int> (26, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++){
                countChar[i][words[i][j]-'a']++;
            }
        }   

        vector<string> result;
        for(int i=0; i<26; i++){

            int c = 0;
            int minCount = 100;

            for(int j=0; j<n; j++){
                if(countChar[j][i] > 0){
                    minCount = min(minCount, countChar[j][i]);
                    c++;
                }
            }

            if(c == n){
                string sub;
                sub.push_back((char) ('a' + i));

                while(minCount--){
                    result.push_back(sub);
                }
            }
                
        }

        return result;
    }
};