#include <iostream>
using namespace std;

class Solution {
public:

    const int mod = 1e9 + 7;

    int countHomogenous(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        long result = 0;
        int i = 0;

        while(i < n){

            char ch = s[i];
            long c = 0;

            while(i < n && ch == s[i]){

                c++;
                i++;
            }

            result = (result + (c * (c + 1) / 2)) % mod;                            
        }

        return result;
    }
};