#include <iostream>
using namespace std;

class Solution {
public:

    int numberOfMatches(int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        return n-1;
    }

    // int numberOfMatches(int n) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int result = 0;

    //     while(n != 1){

    //         if(n & 1){
    //             result += ((n-1) / 2);
    //             n = (((n - 1) / 2) + 1);
                
    //         }
    //         else {
    //             result += (n / 2);
    //             n = (n / 2);
    //         }
    //     }

    //     return result;
    // }
};