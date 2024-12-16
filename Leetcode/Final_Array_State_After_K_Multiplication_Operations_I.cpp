#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int j = 0; j < n; j++) {
            minHeap.push(make_pair(nums[j], j));
        }

        while(k--) {
            auto top = minHeap.top();
            minHeap.pop();
            minHeap.push(make_pair(top.first * multiplier, top.second));
        }

        while(!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            nums[top.second] = top.first;
        }

        return nums;
    }
};