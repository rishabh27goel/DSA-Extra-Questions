#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int first[26];
        int last[26];

        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));

        for(int i=0; i<n; i++){

            if(first[s[i]-'a'] == -1)
                first[s[i]-'a'] = i;

            last[s[i]-'a'] = i;
        }


        int result = -1;

        for(int i=0; i<26; i++){

            result = max(last[i]-first[i]-1, result);
        }

        return result;
    }
};