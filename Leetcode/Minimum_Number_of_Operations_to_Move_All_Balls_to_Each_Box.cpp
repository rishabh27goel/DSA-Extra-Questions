#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = boxes.size();

        vector<int> prefixSum;
        vector<int> boxCount;

        int prefix = 0;
        int box = 0;

        for(int j = 0; j < n; j++) {
            prefix += (boxes[j] == '1' ? j : 0);
            box += (boxes[j]-'0');

            prefixSum.push_back(prefix);
            boxCount.push_back(box);
        }

        vector<int> operations;
        for(int j = 0; j < n; j++) {
            int left = (j - 1 >= 0 ? prefixSum[j-1] : 0);
            int right = prefixSum[n-1] - prefixSum[j];

            int leftCount = (j - 1 >= 0 ? boxCount[j-1] : 0);
            int rightCount = boxCount[n-1] - boxCount[j];

            int leftSum = (j * leftCount) - left;
            int rightSum = right - (j * rightCount);

            operations.push_back(leftSum + rightSum);
        }

        return operations;
    }
};