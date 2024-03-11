#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = order.size();
        int m = s.size();

        string result = "";
        int charCount[26] = {0};

        for(int i=0; i<m; i++){
            charCount[s[i]-'a']++;
        }

        for(int j=0; j<n; j++){
            while(charCount[order[j]-'a']-- > 0){
                result.push_back(order[j]);
            }
        }

        for(int i=0; i<26; i++){
            while(charCount[i]-- > 0){
                result.push_back((char) (i + 'a'));
            }
        }

        return result;
    }
};