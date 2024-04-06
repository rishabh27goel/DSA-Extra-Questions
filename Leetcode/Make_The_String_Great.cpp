#include <iostream>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = s.size();

        int idx = 0;
        string result = "";
        result.push_back(s[0]);

        for(int i=1; i<n; i++){

            if(!result.empty() && abs(s[i] - result[idx]) == 32){
                idx--;
                result.pop_back();
            }
            else {
                result.push_back(s[i]);
                idx++;
            }
        }

        return result;
    }
};