#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // int dp[100001][3];
    // int findMaxSum(int n, vector<vector<int>> &events, int idx, int k) {
    //     // Base Case
    //     if(idx >= n || k <= 0)
    //         return 0;
        
    //     if(dp[idx][k] != -1)
    //         return dp[idx][k];

    //     int pointer = n;
    //     int left = idx + 1;
    //     int right = n-1;

    //     while(left <= right) {
    //         int mid = left + (right - left) / 2;

    //         if(events[mid][0] > events[idx][1]) {
    //             pointer = mid;
    //             right = mid - 1;
    //         }
    //         else {
    //             left = mid + 1;
    //         }   
    //     }

    //     int include = events[idx][2] + findMaxSum(n, events, pointer, k - 1);
    //     int exclude = findMaxSum(n, events, idx + 1, k);

    //     return dp[idx][k] = max(include, exclude);
    // }

    // int maxTwoEvents(vector<vector<int>>& events) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL)

    //     int n = events.size();
    //     sort(events.begin(), events.end());

    //     memset(dp, -1, sizeof(dp));
    //     return findMaxSum(n, events, 0, 2);
    // }

    int maxTwoEvents(vector<vector<int>>& events) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = events.size();

        sort(events.begin(), events.end());
        int maxPrevValue = 0;

        priority_queue<pair<int, int>> maxHeap;
        int maxTotal = 0;

        for(auto &event : events) {
            while(!maxHeap.empty() && -maxHeap.top().first < event[0]) {
                maxPrevValue = max(maxPrevValue, maxHeap.top().second);
                maxHeap.pop();
            }

            maxTotal = max(maxTotal, maxPrevValue + event[2]);
            maxHeap.push(make_pair(-event[1], event[2]));
        }
        
        return maxTotal;
    }
};