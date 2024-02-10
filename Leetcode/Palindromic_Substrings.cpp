#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();
        int result = 0;

        for(int i=0; i<n; i++){

            int start = i;
            int end = i;

            while(start >= 0 && end < n && s[start] == s[end]){
                result++;
                start--;
                end++;
            }

            start = i;
            end = i + 1;

            while(start >= 0 && end < n && s[start] == s[end]){
                result++;
                start--;
                end++;
            }
        }

        return result;
    }
};