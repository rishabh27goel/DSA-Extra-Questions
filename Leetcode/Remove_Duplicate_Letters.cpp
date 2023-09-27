#include <iostream>
using namespace std;

class Solution {
public:

    // Greedy Approach

    string removeDuplicateLetters(string s) {

        int n = s.size();

        bool visited[26] = {0};
        int cnt[26] = {0};
        
        string result = "";

        for(int i=0; i<n; i++){

            cnt[s[i]-'a']++;
        }

        for(int i=0; i<n; i++){

            cnt[s[i]-'a']--;

            // If item is not visited
            if(!visited[s[i]-'a']){

                // If previous in the result string is smaller char then it is fine 
                // but in case of larger char we have to check if it only possibility
                // or better one exist
                while(!result.empty() && result.back() > s[i] && cnt[result.back()-'a'] > 0){

                    visited[result.back()-'a'] = false;
                    result.pop_back();
                }

                visited[s[i]-'a'] = true;
                result.push_back(s[i]);
            }
        }

        return result;
    }
};