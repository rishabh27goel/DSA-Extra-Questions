#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str1.size();
        int m = str2.size();

        int i = 0;
        int j = 0;

        while(i < n) {
            char curr = str1[i];
            char next = ((((str1[i]-'a') + 1) % 26) + 'a');

            if(j < m && (curr == str2[j] || next == str2[j]))
                j++;

            i++;
        } 

        return j == m;
    }
};