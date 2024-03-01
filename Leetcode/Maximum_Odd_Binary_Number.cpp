#include <iostream>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();
        int ones = 0;

        for(int i=0; i<n; i++){

            ones += (s[i] == '1');
        }

        string result = "";
        int c = 0;
 
        while(ones > 1){
            result.push_back('1');
            c++;
            ones--;
        }

        while(c < n-1){
            result.push_back('0');
            c++;
        }

        result.push_back('1');
        return result;
    }
};