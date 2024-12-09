#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        vector<int> bitParity(n);
        bitParity[0] = 0;
        
        for(int i = 1; i < n; i++) {
            if((nums[i-1] % 2) == (nums[i] % 2)) {
                bitParity[i] = bitParity[i-1] + 1;
            }
            else {
                bitParity[i] = bitParity[i-1];
            }
        }

        vector<bool> result;
        for(int j = 0; j < queries.size(); j++) {
            int start = queries[j][0];
            int end = queries[j][1];

            result.push_back((bitParity[end] - bitParity[start] == 0));
        }

        return result;
    }
};