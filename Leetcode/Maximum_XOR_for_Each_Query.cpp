#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int bits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> result(n);
        int xorNum = 0;
        int mask = ((1 << bits) - 1);

        for(int j = 0; j < n; j++) {
            xorNum ^= nums[j];
            result[n-j-1] = (xorNum ^ mask);
        }

        return result;
    }
};