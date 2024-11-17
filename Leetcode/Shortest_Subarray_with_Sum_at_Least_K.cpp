#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    // Current prefix - previous smallest prefix >= k
    // int shortestSubarray(vector<int>& nums, int k) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> minHeap;
    //     long prefix = 0;
    //     int shortest = n + 1;

    //     for(int j = 0; j < n; j++) {
    //         prefix += nums[j];
    //         if(prefix >= k)  shortest = min(shortest, j + 1);

    //         while(!minHeap.empty() && prefix - minHeap.top().first >= k) {
    //             shortest = min(shortest, j - minHeap.top().second);
    //             minHeap.pop();
    //         }

    //         minHeap.push(make_pair(prefix, j));
    //     }

    //     return shortest > n ? -1 : shortest;
    // }

    // int shortestSubarray(vector<int>& nums, int k) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     deque<pair<long , int>> qIdx;
    //     long prefix = 0;
    //     int shortest = n + 1;

    //     for(int j = 0; j < n; j++) {
    //         prefix += nums[j];
    //         if(prefix >= k)  shortest = min(shortest, j + 1);

    //         while(!qIdx.empty() && prefix - qIdx.front().first >= k) {
    //             shortest = min(shortest, j - qIdx.front().second);
    //             qIdx.pop_front();
    //         }

    //         while(!qIdx.empty() && prefix <= qIdx.back().first) {
    //             qIdx.pop_back();
    //         }

    //         qIdx.push_back(make_pair(prefix, j));
    //     }

    //     return shortest > n ? -1 : shortest;
    // }

    long prefix[100001];
    int shortestSubarray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        long sum = 0;
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            prefix[j] = sum;
        }

        deque<int> qIdx;
        int shortest = n + 1;
        for(int j = 0; j < n; j++) {
            if(prefix[j] >= k)  shortest = min(shortest, j + 1);

            while(!qIdx.empty() && prefix[j] - prefix[qIdx.front()] >= k) {
                shortest = min(shortest, j - qIdx.front());
                qIdx.pop_front();
            }

            while(!qIdx.empty() && prefix[j] <= prefix[qIdx.back()]) {
                qIdx.pop_back();
            }

            qIdx.push_back(j);
        }
        return shortest > n ? -1 : shortest;
    }
};