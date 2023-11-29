#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int bits = 0;

        while(n != 0){

            bits += ((n & 1) != 0);

            n >>= 1;
        }

        return bits;
    }
};