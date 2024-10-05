#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(s1.size() > s2.size())
            return false;

        int n = s2.size();

        int charCount[26] = {0};
        for(int j = 0; j < s1.size(); j++) {
            charCount[s1[j]-'a']++;
        }

        int charCurr[26] = {0};
        int i = 0;

        for(int j = 0; j < n; j++) {
            if(j >= s1.size())
                charCurr[s2[i++]-'a']--;

            charCurr[s2[j]-'a']++;

            bool valid = true;
            for(int k = 0; k < 26; k++) {
                if(charCount[k] != 0 && charCount[k] != charCurr[k]) {
                    valid = false;
                    break;
                }
            }

            if(valid)
                return true;
        }

        return false;
    }
};