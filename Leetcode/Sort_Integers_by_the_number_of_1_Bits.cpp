#include <iostream>
using namespace std;

class Solution {
public:

    // int findBitCount(int &num){

    //     int val = num;
    //     int bits = 0;

    //     while(val != 0){

    //         if(val & 1)
    //             bits++;

    //         val >>= 1;
    //     }

    //     return bits;
    // }

    // vector<int> sortByBits(vector<int>& arr) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = arr.size();

    //     // Sort of array
    //     sort(arr.begin(), arr.end(), [&](int &a, int &b){

    //         int bitCount1 = findBitCount(a);
    //         int bitCount2 = findBitCount(b);

    //         if(bitCount1 == bitCount2)
    //             return a < b;

    //         return bitCount1 < bitCount2;
    //     });

    //     return arr;
    // }

    vector<int> sortByBits(vector<int>& arr) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        // Sort of array
        sort(arr.begin(), arr.end(), [&](int &a, int &b){

            int bitCount1 = __builtin_popcount(a);
            int bitCount2 = __builtin_popcount(b);

            if(bitCount1 == bitCount2)
                return a < b;

            return bitCount1 < bitCount2;
        });

        return arr;
    }
};