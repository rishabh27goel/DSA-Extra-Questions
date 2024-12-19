#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = arr.size();

        int splits = 0;
        int maxNum = 0;

        for(int j = 0; j < n; j++) {
            maxNum = max(maxNum, arr[j]);
            if(maxNum == j)
                splits++;
        }

        return splits;
    }
};