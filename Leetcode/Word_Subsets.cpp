#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    //     int m = words2.size();

    //     vector<vector<int>> charCount(m, vector<int> (26, 0));
    //     for(int k = 0; k < m; k++) {
    //         for(int j = 0; j < words2[k].size(); j++) {
    //             charCount[k][words2[k][j]-'a']++;
    //         }
    //     }

    //     vector<string> result;
    //     for(int j = 0; j < words1.size(); j++) {
    //         int charParent[26] = {0};
    //         for(int k = 0; k < words1[j].size(); k++) {
    //             charParent[words1[j][k]-'a']++;
    //         }

    //         int subsCount = 0;
    //         for(int k = 0; k < m; k++) {
    //             bool valid = true;
    //             for(int i = 0; i < 26; i++) {
    //                 if(charCount[k][i] == 0)  continue;

    //                 if(charParent[i] < charCount[k][i]) {
    //                     valid = false;
    //                     break;
    //                 }
    //             }
    //             if(valid)   subsCount++;
    //         }
            
    //         if(subsCount == words2.size()) {
    //             result.push_back(words1[j]);
    //         }
    //     }

    //     return result;
    // }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = words1.size();
        int m = words2.size();

        int univCount[26] = {0};
        for(auto &word : words2) {
            int currCount[26] = {0};
            for(int j = 0; j < word.size(); j++) {
                currCount[word[j]-'a']++;
            }

            for(int j = 0; j < 26; j++) {
                univCount[j] = max(currCount[j], univCount[j]);
            }
        }

        vector<string> result;
        for(auto &word : words1) {
            int currCount[26] = {0};
            for(int j = 0; j < word.size(); j++) {
                currCount[word[j]-'a']++;
            }

            bool valid = true;
            for(int j = 0; j < 26; j++) {
                if(univCount[j] == 0)   continue;

                if(univCount[j] > currCount[j]) {
                    valid = false;
                    break;
                }
            }
            if(valid)   result.push_back(word);
        } 

        return result;
    }
};