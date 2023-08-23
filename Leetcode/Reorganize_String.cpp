#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size();

        int charCount[26] = {0};
        int maxNum = 0;
        int maxIdx = -1;

        for(int i=0; i<n; i++){

            if(++charCount[s[i]-'a'] > maxNum){

                maxNum = charCount[s[i]-'a'];
                maxIdx = (s[i]-'a');
            }
        }


        if(maxNum > ((n + 1) / 2))
            return "";


        int i = 0;

        while(maxNum--){

            s[i] = (char) ('a' + maxIdx);
            i += 2;
        }

        for(int j=0; j<26; j++){

            if(j == maxIdx || charCount[j] == 0)
                continue;

            while(charCount[j]--){

                if(i >= n)
                    i = 1;

                s[i] = (char)('a' + j);
                i += 2;
            }
        }

        return s;
    }
};