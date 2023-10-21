#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    // int constrainedSubsetSum(vector<int>& nums, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     priority_queue<pair<int, int>> pq;
    //     pq.push(make_pair(nums[0], 0));

    //     int result = nums[0];

    //     for(int i=1; i<n; i++){

    //         while(!pq.empty() && i - pq.top().second > k){

    //             pq.pop();
    //         }

    //         int curr = max(0, pq.top().first) + nums[i];
    //         result = max(curr, result);
    //         pq.push({curr, i});
    //     }

    //     return result;
    // } 

    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        deque<int> dq;
        vector<int> dp(n);

        for(int i=0; i<n; i++){

            if(!dq.empty() && i - dq.front() > k){

                dq.pop_front();
            }

            dp[i] = (dq.empty() ? 0 : dp[dq.front()]) + nums[i];

            while(!dq.empty() && dp[dq.back()] < dp[i]){

                dq.pop_back();
            }

            if(dp[i] > 0){

                dq.push_back(i);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};