#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        unordered_map<char, char> mps;
        unordered_map<char, char> mpt;

        for(int i=0; i<n; i++){
            if(mps.find(s[i]) == mps.end() && mpt.find(t[i]) == mpt.end()){
                mps[s[i]] = t[i];
                mpt[t[i]] = s[i];
            }
            else {
                if(mps[s[i]] != t[i] || mpt[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};