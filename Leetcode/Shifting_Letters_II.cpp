#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string str, vector<vector<int>>& shifts) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = str.size();

        vector<int> shiftsCount(n + 1, 0);
        for(int j = 0; j < shifts.size(); j++) {
            int left = shifts[j][0];
            int right = shifts[j][1] + 1;

            shiftsCount[left] += (shifts[j][2] ? 1 : -1);
            shiftsCount[right] += (shifts[j][2] ? -1 : 1);
        }

        int count = 0;
        for(int j = 0; j < n; j++) {
            count += shiftsCount[j];
            str[j] = (char) ((((str[j] - 'a' + count) % 26) + 26) % 26) + 'a';
        }

        return str;
    }
};