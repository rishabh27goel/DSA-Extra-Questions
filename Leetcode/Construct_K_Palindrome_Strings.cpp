#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string str, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        if(n < k)
            return false;

        int charCount[26] = {0};
        for(int j = 0; j < n; j++) {
            charCount[str[j]-'a']++;
        }

        int oddCount = 0;
        for(int j = 0; j < 26; j++) {
            if(charCount[j] % 2 == 1)
                oddCount++;
        }

        if(oddCount <= k)
            return true;

        return false;
    }
};