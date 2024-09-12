#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int charCount[26] = {0};
        for(int j = 0; j < allowed.size(); j++) {
            charCount[allowed[j]-'a']++;
        }

        int wordCount = 0;
        for(int j = 0; j < words.size(); j++) {
            bool valid = true;
            for(int idx = 0; idx < words[j].size(); idx++) {
                if(charCount[words[j][idx]-'a'] == 0) {
                    valid = false;
                    break;
                }
            }
            if(valid)  
                wordCount++;
        }
        return wordCount;
    }
};