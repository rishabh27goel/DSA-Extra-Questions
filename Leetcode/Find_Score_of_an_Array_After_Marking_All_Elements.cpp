#include <iostream>
#include <ranges>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<bool> visited(n, false);

        for(int j = 0; j < n; j++) {
            minHeap.push(make_pair(nums[j], j));
        }

        long long totalScore = 0;
        while(!minHeap.empty()) {
            while(!minHeap.empty() && visited[minHeap.top().second]) {
                minHeap.pop();
            }

            if(minHeap.empty()) 
                break;

            auto smallest = minHeap.top();
            totalScore += smallest.first;
            minHeap.pop();

            if(smallest.second - 1 >= 0)    visited[smallest.second - 1] = true;
            visited[smallest.second] = true;
            if(smallest.second + 1 < n)    visited[smallest.second + 1] = true;
        }
        
        return totalScore;
    }

    // long long findScore(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     vector<int> idxs;
    //     for(int i = 0; i < n; i++)
    //         idxs.push_back(i);

    //     ranges::stable_sort(idxs, [&](int x, int y) {
    //         if(nums[x] == nums[y])
    //             return x < y;

    //         return nums[x] < nums[y];
    //     });

    //     int visited[n];
    //     memset(visited, 0, 4 * n);

    //     long long totalScore = 0;
    //     int j = 0;
        
    //     while(true) {
    //         while(j < n && visited[idxs[j]]) 
    //             j++;

    //         if(j == n)
    //             break;

    //         totalScore += nums[idxs[j]];

    //         if(idxs[j] - 1 >= 0)  visited[idxs[j] - 1] = true;
    //         visited[idxs[j]] = true;
    //         if(idxs[j] + 1 < n)  visited[idxs[j] + 1] = true;
    //     }

    //     return totalScore;
    // }
};
