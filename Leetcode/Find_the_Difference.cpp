#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n1 = s.size();
        int n2 = t.size();

        int xorVal = 0;

        for(int i=0; i<n1; i++){

            xorVal ^= (int) s[i];
            xorVal ^= (int) t[i];
        }

        xorVal ^= (int) t[n2-1];

        return (char) (xorVal);
    }

    // char findTheDifference(string s, string t) {
        
    //     int n1 = s.size();
    //     int n2 = t.size();

    //     int sum = 0;

    //     for(int i=0; i<n1; i++){

    //         sum += (int) t[i];
    //         sum -= (int) s[i];
    //     }

    //     sum += (int) t[n2-1];

    //     return (char) sum;
    // }
};