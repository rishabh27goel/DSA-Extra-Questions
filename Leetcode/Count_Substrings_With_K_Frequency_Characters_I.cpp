#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string str, int k) {
        int n = str.size();

        vector<int> chars(26, 0);
        int totalSubs = (n * (n + 1)) / 2;

        int currTotal = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            chars[str[j]-'a']++;

            while(i <= j && chars[str[j]-'a'] == k) {
                chars[str[i]-'a']--;
                i++;
            }

            currTotal += (j - i + 1);
            j++;
        }

        return totalSubs - currTotal;
    }
};