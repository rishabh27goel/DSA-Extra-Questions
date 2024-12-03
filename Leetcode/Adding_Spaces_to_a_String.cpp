#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = s.size();
        int m = spaces.size();

        string modStr = "";
        int j = 0;

        for(int i = 0; i < n; i++) {
            if(j < m && spaces[j] == i) {
                modStr.push_back(' ');
                j++;
            }
            modStr.push_back(s[i]);
        }

        return modStr;
    }
};