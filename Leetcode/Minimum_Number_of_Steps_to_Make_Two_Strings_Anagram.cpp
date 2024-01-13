#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int charCount[26] = {0};

        for(int i=0; i<n; i++){

            charCount[s[i]-'a']++;
            charCount[t[i]-'a']--;
        }   

        int total = 0;

        for(int i=0; i<26; i++){

            if(charCount[i] < 0)
                total += abs(charCount[i]);
        }

        return total;
    }
};