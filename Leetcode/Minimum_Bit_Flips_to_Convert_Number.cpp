#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        unsigned int mask = (1 << 31);
        int bitCount = 0;
        while(mask != 0) {
            int bit1 = ((start & mask) ? 1 : 0);
            int bit2 = ((goal & mask) ? 1 : 0);

            bitCount += (bit1 != bit2);
            mask >>= 1;
        }
        return bitCount;
    }
};