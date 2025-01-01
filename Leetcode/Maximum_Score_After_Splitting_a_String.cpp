#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(string str) {
        int n = str.size();

        int ones = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == '1')
                ones++;
        }

        int maxScore = 0;
        int zero = 0;

        for(int i = 0; i < n-1; i++) {
            if(str[i] == '1')
                ones--;
            else
                zero++;

            maxScore = max(maxScore, zero + ones);
        }
        
        return maxScore;
    }
};