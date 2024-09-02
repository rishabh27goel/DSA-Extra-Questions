#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = chalk.size();

        long prefixSum = 0;
        for(int i = 0; i < n; i++) {
            prefixSum += chalk[i];
        }

        long remaining = k % prefixSum;
        prefixSum = 0;

        for(int i = 0; i < n; i++) {
            prefixSum += chalk[i];

            if(prefixSum > remaining)
                return i;
        }

        return -1;
    }
};