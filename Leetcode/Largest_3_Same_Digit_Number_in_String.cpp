#include <iostream>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = num.size();

        char ch = '/';
        int i = 0;
        
        while(i < n){

            int c = 0;
            char digit = num[i];

            while(i < n && digit == num[i]){
                
                c++;
                i++;
            }

            if(c >= 3){

                if(ch < digit){

                    ch = digit;
                }
            }                
        }

        if(ch == '/')
            return "";

        string result = "";
        result.push_back(ch);
        result.push_back(ch);
        result.push_back(ch);

        return result;
    }
};