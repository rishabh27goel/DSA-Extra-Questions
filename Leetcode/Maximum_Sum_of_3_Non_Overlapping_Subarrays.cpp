#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dp[20001][4];
    int findMaxSum(int n, vector<int> &sum, int k, int idx, int size) {
        // Base Case
        if(idx >= n || size == 0 || n - idx < k)
            return 0;

        if(dp[idx][size] != -1)
            return dp[idx][size];

        int left = (idx - 1 >= 0 ? sum[idx - 1] : 0);
        int right = sum[idx + k - 1];

        int include = right - left + findMaxSum(n, sum, k, idx + k, size - 1);
        int exclude = findMaxSum(n, sum, k, idx + 1, size);

        return dp[idx][size] = max(include, exclude);
    }

    vector<int> position;
    void findIndexes(int n, vector<int> &sum, int k, int idx, int size, int maxSum) {
        // Base Case
        if(idx >= n || size == 0 || n - idx < k)
            return;

        if(maxSum == 0) {
            for(auto idx : position) {
                cout << idx << " ";
            }
            return;
        }
        
        int left = (idx - 1 >= 0 ? sum[idx - 1] : 0);
        int right = sum[idx + k - 1];

        int include = (right - left) + findMaxSum(n, sum, k, idx + k, size - 1);
        int exclude = findMaxSum(n, sum, k, idx + 1, size);

        if(include == maxSum) {
            position.push_back(idx);
            findIndexes(n, sum, k, idx + k, size - 1, maxSum - (right - left));
        }
        else {
            findIndexes(n, sum, k, idx + 1, size, maxSum);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        memset(dp, -1, sizeof(dp));

        vector<int> prefixSum;
        int prefix = 0;

        for(int j = 0; j < n; j++) {
            prefix += nums[j];
            prefixSum.push_back(prefix);
        }

        int maxSum = findMaxSum(n, prefixSum, k, 0, 3);
        findIndexes(n, prefixSum, k, 0, 3, maxSum);

        return position;
    }
};