#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    long long minEnd(int n, int x) {
        if(--n == 0)
            return x;

        long long minNum = 0;
        long long mask = 1;

        int j = 0;
        while(n > 0) {
            if((mask & x) == 0) {
                if(n & 1) minNum += mask;
                n >>= 1;
            }
            mask <<= 1;
        }

        return x + minNum;
    }
};