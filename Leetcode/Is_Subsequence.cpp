#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n1  = s.size();
        int n2 = t.size();

        int i = 0;
        int j = 0 ;

        while(j < n2 && i < n1){

            if(t[j] == s[i]){

                i++;
            }

            j++;
        }

        return i == n1;
    }
};