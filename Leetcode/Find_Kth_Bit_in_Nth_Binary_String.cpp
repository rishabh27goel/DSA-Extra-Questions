#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // string findBitHelper(int n) {
    //     // Base Case
    //     if(n == 1)
    //         return "0";

    //     string last = findBitHelper(n - 1);
    //     string result = "";

    //     result += last;
    //     result += "1"; 

    //     reverse(last.begin(), last.end());
    //     for(int j = 0; j < last.size(); j++) {
    //         last[j] = (last[j] == '1' ? '0' : '1');
    //     }

    //     result += last;
    //     return result;
    // }

    // char findKthBit(int n, int k) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     string str =  findBitHelper(n);
    //     return str[k - 1];
    // }

    char findKthBit(int n, int k) {
        if(n == 1)
            return '0';

        int strLen = (1 << n) - 1;
        int middle = (strLen / 2) + 1;

        if(middle == k)
            return '1';

        if(middle > k)
            return findKthBit(n - 1, k);
        else
            return (findKthBit(n - 1, strLen - k + 1) == '1' ? '0' : '1');
    }
};