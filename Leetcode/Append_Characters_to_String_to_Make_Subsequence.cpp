#include <iostream>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n1 = s.size();
        int n2 = t.size();

        int c = 0;
        int i = 0;
        int j = 0;

        while(i < n1){
            if(t[j] == s[i]) {
                j++;
            }
            i++;
        }

        return n2 - j;
    }
};