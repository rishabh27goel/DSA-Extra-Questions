#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = s.size();

        int result = 0;
        int total = 0;
        
        int i = 0;
        int j = 0;

        while(j < n){

            int curr = abs(s[j] - t[j]);
            total += curr;

            while(i <= j && maxCost < total){
                int prev = abs(s[i] - t[i]);
                total -= prev;
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};