#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumLength(string str) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        int charCount[26] = {0};
        for(int j = 0; j < n; j++) {
            charCount[str[j]-'a']++;
        }
    
        int total = 0;
        for(int j = 0; j < 26; j++) {
            if(charCount[j] == 0)   continue;

            total += (charCount[j] % 2 == 0 ? 2 : 1);
        }

        return total;
    }
};