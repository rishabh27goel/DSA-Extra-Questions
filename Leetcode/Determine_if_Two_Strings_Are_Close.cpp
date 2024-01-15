#include <iostream>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(word1.size() != word2.size())
            return false;

        int n = word1.size();
   
        vector<int> charCount1(26, 0);
        vector<int> charCount2(26, 0);
        
        for(int i=0; i<n; i++){

            charCount1[word1[i]-'a']++;
            charCount2[word2[i]-'a']++;
        }

        // Check if all the char of strings are equal or not
        for(int i=0; i<26; i++){

            if(charCount1[i] == 0 && charCount2[i] != 0)
                return false;

            if(charCount2[i] == 0 && charCount1[i] != 0)
                return false;
        }

        sort(charCount1.begin(), charCount1.end());
        sort(charCount2.begin(), charCount2.end());
    
        for(int i=25; i>=0; i--){

            if(charCount1[i] != charCount2[i])  
                return false;
        }

        return true;
    }
};