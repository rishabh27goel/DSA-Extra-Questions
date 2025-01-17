#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = derived.size();

        int totalXor = 0;
        for(int j = 0; j < n; j++) {
            totalXor ^= derived[j];
        }

        return totalXor == 0;
    }
};