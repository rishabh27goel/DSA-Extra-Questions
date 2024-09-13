#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = arr.size();

        vector<int> xorSum(n);
        int prefix = 0;

        for(int j = 0; j < n; j++) {
            prefix ^= arr[j];
            xorSum[j] = prefix;
        }

        vector<int> query;
        for(int j = 0; j < queries.size(); j++) {
            int x = queries[j][0];
            int y = queries[j][1];

            int left = (x - 1 >= 0 ? xorSum[x-1] : 0);
            query.push_back(left ^ xorSum[y]);
        }

        return query;
    }
};