#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        unordered_map<string, int> firstMap;
        unordered_map<string, int> secondMap;

        stringstream firstSS(s1);
        string word;

        while(firstSS >> word) {
            firstMap[word]++;
        }

        stringstream secondSS(s2);
        while(secondSS >> word) {
            secondMap[word]++;
        }

        vector<string> words;
        for(auto itr : firstMap) {
            if(itr.second == 1) {
                if(secondMap.find(itr.first) == secondMap.end())
                    words.push_back(itr.first);
            }
        }
        for(auto itr : secondMap) {
            if(itr.second == 1) {
                if(firstMap.find(itr.first) == firstMap.end())
                    words.push_back(itr.first);
            }
        }

        return words;    
    }
};