#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumSteps(string str) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        long long steps = 0;
        int ones = 0;

        for(int j = 0; j < n; j++) {
            if(str[j] == '1')
                ones++;
            else
                steps += ones;
        }

        return steps;
    }
};