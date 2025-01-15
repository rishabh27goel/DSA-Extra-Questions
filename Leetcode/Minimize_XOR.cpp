#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = 0;
        while(num2 > 0) {
            if(num2 & 1)
                setBits++;
                
            num2 >>= 1;
        }

        vector<int> bitSet(35, 0);
        int totalBits = 0;
        int c = 0;

        while(num1 > 0) {
            int bit = ((num1 & 1) ? 1 : 0);
            totalBits += bit;

            bitSet[c++] = bit;
            num1 >>= 1;
        }

        if(setBits >= totalBits) {
            int remBits = setBits - totalBits;
            for(int j = 0; j < 35 && remBits > 0; j++) {
                if(bitSet[j] == 0) {
                    bitSet[j] = 1;
                    remBits--;
                }
            }
        }
        else {
            int remBits = totalBits - setBits;
            for(int j = 0; j < 35 && remBits > 0; j++) {
                if(bitSet[j] == 1) {
                    bitSet[j] = 0;
                    remBits--;
                }
            }
        }

        long xVal = 0;
        long mask = 1;

        for(int j = 0; j < 35; j++) {
            if(bitSet[j] == 1)
                xVal += mask;

            mask <<= 1;
        }

        return xVal;
    }
};