#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int findComplement(int num) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int mask = 1;
    //     int complement = 0;

    //     while(num != 0) {
    //         if(!(num & 1))
    //             complement += mask;

    //         num >>= 1;
    //         mask <<= 1;
    //     }

    //     return complement;
    // }

    int findComplement(int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long bits = log2(num) + 1;
        long mask = ((long) 1 << (long) bits) - 1;

        return num ^ mask;
    }
};