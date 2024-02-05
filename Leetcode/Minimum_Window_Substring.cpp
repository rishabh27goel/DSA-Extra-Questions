#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n1 = s.size();
        int n2 = t.size();

        if(t.size() > s.size())
            return "";

        int charCount1[128] = {0};
        int charCount2[128] = {0};
    
        for(int i=0; i<n2; i++){
            charCount2[t[i]]++;
        }

        int startIdx = -1;
        int minLen = n1 + 1;

        int c = 0;
        int start = 0;
        int end = 0;

        while(end < n1){

            // Add elements in window
            while(end < n1 && c < n2){
                
                // If the current char exists in t string
                if(charCount2[s[end]] > 0 && ++charCount1[s[end]] <= charCount2[s[end]])
                    c++;

                end++;
            }

            if(end == n1 && c < n2)
                break;

            // Try to minimize the window
            while(start <= end && c == n2){

                if(end - start < minLen){
                    minLen = end - start;
                    startIdx = start;
                }

                if(charCount2[s[start]] != 0 && --charCount1[s[start]] < charCount2[s[start]])
                    c--;

                start++;
            }
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};