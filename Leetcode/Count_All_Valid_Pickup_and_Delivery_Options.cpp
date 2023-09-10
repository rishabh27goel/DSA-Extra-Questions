#include <iostream>
using namespace std;

class Solution {
public:

    const int mod = 1e9 + 7;

    // int countOrders(int n) {
        
    //     if(n == 1)
    //         return 1;

    //     int options = (2 * n) - 1;

    //     long count = (options * (options + 1)) / 2;

    //     return (count * countOrders(n-1)) % mod;
    // }

    int countOrders(int n) {
        
        long total = 1;

        for(int num=2; num<=n; num++){

            int spaces = ((2 * num) - 1);
            int currCount = (spaces * (spaces + 1)) / 2;

            total = (currCount * total) % mod;
        }

        return (int) (total % mod);
    }
};