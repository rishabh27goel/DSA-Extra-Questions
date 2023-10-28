#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int maxLen = 0;
        int idx = 0;

        for(int i=0; i<n; i++){

            int l = i;
            int r = i;

            while(l >= 0 && r < n && s[l] == s[r]){

                if(maxLen < r - l + 1){

                    idx = l;
                    maxLen = r - l + 1;
                }

                l--; r++;
            }

            
            l = i;
            r = i+1;

            while(l >= 0 && r < n && s[l] == s[r]){

                if(maxLen < r - l + 1){

                    idx = l;
                    maxLen = r - l + 1;
                }

                l--; r++;
            }
        }

        return s.substr(idx, maxLen);
    }
};