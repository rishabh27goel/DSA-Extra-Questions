#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        long long totalSum = 0;
        priority_queue<int> maxHeap;

        for(int j = 0; j < n; j++) {
            totalSum += gifts[j];
            maxHeap.push(gifts[j]);
        }

        while(k--) {
            int top = (int) sqrt(maxHeap.top());
            totalSum -= maxHeap.top();
            totalSum += top;
            
            maxHeap.pop();
            maxHeap.push(top);
        }

        return totalSum;
    }
};