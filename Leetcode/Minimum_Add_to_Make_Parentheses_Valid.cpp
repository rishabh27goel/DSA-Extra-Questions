#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string str) {
        int n = str.size();

        int open = 0;
        int closed = 0;

        for(int j = 0; j < n; j++) {
            if(str[j] == '(') {
                open++;
            }
            else {
                if(open > 0)
                    open--;
                else
                    closed++;
            }
        }

        return open + closed;
    }
};