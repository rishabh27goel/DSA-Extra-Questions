#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = word.size();

        long long result = 0;
        long prefixMask = 0;
        long freq[1024] = {1};

        for(int i=0; i<n; i++){
            
            long mask = (1 << (word[i]-'a'));
            prefixMask ^= mask;

            result += freq[prefixMask];

            for(int j=0; j<10; j++){
                result += freq[prefixMask ^ (1 << j)];
            }

            freq[prefixMask]++;
        }

        return result;
    }
};