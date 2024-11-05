#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minChanges(string str) {
        int n = str.size();

        int result = 0;
        int j = 0;

        while(j < n) {
            int c = ((str[j]-'0') + (str[j+1]-'0')) % 2;
            result += c;
            j += 2;
        }
    
        return result;
    }
};