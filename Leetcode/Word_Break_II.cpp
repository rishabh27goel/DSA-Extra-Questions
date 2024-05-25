#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:

    unordered_set<string> words;

    void findWordBreak(int n, string &s, int idx, string match, vector<string> &result){

        // Base Case
        if(idx == n){
            result.push_back(match);
            return;
        }

        string curr = "";
        for(int j=idx; j<n; j++){

            curr.push_back(s[j]);

            // Find the word in the set
            if(words.find(curr) != words.end()){
                if(match.size() > 0){
                    findWordBreak(n, s, j+1, match + " " + curr, result);
                }
                else {
                    findWordBreak(n, s, j+1, match + curr, result);
                }
            }
        }
    }   

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        for(int i=0; i<wordDict.size(); i++){
            words.insert(wordDict[i]);
        }   

        vector<string> result;
        findWordBreak(n, s, 0, "", result);
    
        return result;
    }
};