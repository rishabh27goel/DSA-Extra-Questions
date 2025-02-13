#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int numSize = nums.size();

        priority_queue<long, vector<long>, greater<long>> smallestNumberQueue;
        for(int numIdx = 0; numIdx < numSize; numIdx++) {
            smallestNumberQueue.push(nums[numIdx]);
        }
        
        int operations = 0;
        while(!smallestNumberQueue.empty()) {
            long smallestNumber = smallestNumberQueue.top();
            smallestNumberQueue.pop();

            if(smallestNumberQueue.empty() || smallestNumber >= k)  
                break;

            long secondSmallestNumber = smallestNumberQueue.top();
            smallestNumberQueue.pop();

            smallestNumberQueue.push(2 * min(smallestNumber, secondSmallestNumber) + max(smallestNumber, secondSmallestNumber));
            operations++;
        }
        return operations;
    }
};