#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        string combine = (s + s);

        // Some substring satisfy the condition 
        if(combine.substr(1, (2 * n) - 2).find(s) != -1)
            return true;

        return false;
    }
};