#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canBeValid(string str, string locked) {
        int n = str.size();

        if(n % 2 == 1)
            return false;

        int open = 0;
        int extra = 0;

        for(int j = 0; j < n; j++) {
            if(locked[j] == '1') {
                if(str[j] == '(')
                    open++;
                else
                    open--;
            }
            else 
                extra++;
        
            if(open + extra < 0)
                return false;
        }

        int close = 0;
        extra = 0;

        for(int j = n-1; j >= 0; j--) {
            if(locked[j] == '1') {
                if(str[j] == ')')
                    close++;
                else
                    close--;
            }
            else 
                extra++;
        
            if(close + extra < 0)
                return false;
        }

        return true;
    }
};