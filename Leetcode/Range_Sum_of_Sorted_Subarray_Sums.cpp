#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // int rangeSum(vector<int>& nums, int n, int left, int right) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int mod = 1e9 + 7;
    //     vector<int> subSum;
    //     for(int i=0; i<n; i++){
            
    //         int sum = 0;
    //         for(int j=i; j<n; j++){
    //             sum += nums[j];
    //             subSum.push_back(sum);
    //         }
    //     }
    //     sort(subSum.begin(), subSum.end());

    //     long totalSum = 0;
    //     for(int j=left-1; j<=right-1; j++){
    //         totalSum = (totalSum + subSum[j]) % mod;
    //     }

    //     return totalSum;
    // }

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int mod = 1e9 + 7;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(int i=0; i<n; i++){
            minHeap.push({ nums[i], i });
        }

        long totalSum = 0;
        int start = 1;
        while(!minHeap.empty() && start <= right){
            auto smallest = minHeap.top();
            minHeap.pop();

            if(start >= left)   totalSum = (totalSum + smallest.first) % mod;
            if(smallest.second + 1 < n){
                minHeap.push({ smallest.first + nums[smallest.second + 1], smallest.second + 1 });
            }

            start++;
        }

        return totalSum;
    }
};