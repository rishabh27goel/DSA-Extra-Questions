#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findHash(char ch) {
        if(ch == 'a')
            return (1 << 4);
        else if(ch == 'e')
            return (1 << 3);
        else if(ch == 'i')
            return (1 << 2);
        else if(ch == 'o')
            return (1 << 1);
        else if(ch == 'u')
            return 1;
        else
            return 0;
    }

    // This problem looks like a sliding window problem
    // But we have to think about parity of vowels in this problem
    // a e i o u -> 0 0 0 0 0  (means all the chars are even in number)
    int findTheLongestSubstring(string str) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        // unordered_map<int, int> hashMap;
        vector<int> hashMap(32, -1);
        int prefixHash = 0;
        int j = 0;

        int maxLength = 0;
        while(j < n) {
            int hash = findHash(str[j]);
            prefixHash ^= hash;

            if(prefixHash == 0)  maxLength = max(maxLength, j + 1);            
            if(hashMap[prefixHash] == -1) {
                hashMap[prefixHash] = j;
            }
            else {
                maxLength = max(maxLength, j - hashMap[prefixHash]); 
            }

            j++;
        }

        return maxLength;
    }
};