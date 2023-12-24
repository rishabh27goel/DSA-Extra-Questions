#include <iostream>
using namespace std;

class Solution {
public:

    // int findCount(int n, string &str, int start){

    //     int c = ((str[0]-'0') == start ? 0 : 1);

    //     for(int i=1; i<n; i++){

    //         if((str[i]-'0') != !start){

    //             c++;
    //         }

    //         start = !start;
    //     }

    //     return c;
    // }

    // int minOperations(string s) {
        
    //     int n = s.size();

    //     if(n == 1)
    //         return 0;

    //     return min(findCount(n, s, 0), findCount(n, s, 1));
    // }

    int minOperations(string s) {
        
        int n = s.size();

        if(n == 1)
            return 0;

        int total = ((s[0]-'0') != 0);
        int start = 0;

        for(int i=1; i<n; i++){

            start = !start;

            if((s[i]-'0') != start){

                total++;
            }
        }

        return min(total, n - total);
    }
};