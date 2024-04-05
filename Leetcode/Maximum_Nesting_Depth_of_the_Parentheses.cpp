#include <iostream>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int maxDepth = 0;
        int c = 0;

        for(int i=0; i<n; i++){

            if(s[i] == '('){
                c++;
            }
            else if(s[i] == ')'){
                c--;
            }

            maxDepth = max(c, maxDepth);
        }

        return maxDepth;
    }
};