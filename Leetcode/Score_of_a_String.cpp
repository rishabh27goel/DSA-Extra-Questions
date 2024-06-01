#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        
        int n = s.size();

        int result = 0;
        for(int i=0; i<n-1; i++){
            result += abs(s[i] - s[i+1]);
        }

        return result;
    }
};