#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        long long maximumHappinessSum(vector<int>& happiness, int k) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
    
            int size = happiness.size();
    
            priority_queue<int> maxHeap;
            for(int currIdx = 0; currIdx < size; currIdx++)
                maxHeap.push(happiness[currIdx]);
    
            long long totalSum = 0;
            int numCount = 0;
    
            while(k--) {
                int topValue = maxHeap.top();
                maxHeap.pop();
                
                if(topValue - numCount <= 0)   return totalSum;
                totalSum += (topValue - numCount);
                numCount++;
            }
            return totalSum;
        }
    };