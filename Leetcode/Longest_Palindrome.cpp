#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int countS[128] = {0};
        for(int i=0; i<n; i++){
            countS[s[i]]++;
        }

        int length = 0;
        int oneExist = false;

        for(int i=0; i<128; i++){
            if(countS[i] == 0)  
                continue;

            if(countS[i] % 2 == 0){
                length += countS[i];
            }
            else {
                length += (countS[i] - 1); 
                oneExist = true;
            }
        }

        return oneExist ? length + 1 : length;
    }
};