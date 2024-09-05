#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int totalSum = 0;
        for(int j = 0; j < rolls.size(); j++) {
            totalSum += rolls[j];
        }
        int leftOver = ((rolls.size() + n) * mean) - totalSum;

        if(leftOver < n || leftOver > 6 * n)
            return {};

        int common = leftOver / n;
        int rem = leftOver % n;

        vector<int> missing(n, common);
        int j = 0;
        
        while(rem--) {
            missing[j++]++;
        }

        return missing;
    }
};