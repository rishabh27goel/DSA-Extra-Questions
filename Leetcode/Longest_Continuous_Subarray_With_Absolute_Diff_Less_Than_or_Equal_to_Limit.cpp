#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    // Time : O(n * log(n))   Space : O(n) 
    // int longestSubarray(vector<int>& nums, int limit) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;
    //     priority_queue<pair<int, int>> maxQ;

    //     int result = 0;
    //     int i = 0;
    //     int j = 0;

    //     while(j < n){
    //         maxQ.push(make_pair(nums[j], j));
    //         minQ.push(make_pair(nums[j], j));

    //         while(i <= j && maxQ.top().first - minQ.top().first > limit){
    //             // Remove elements
    //             while(!maxQ.empty() && maxQ.top().second <= i){
    //                 maxQ.pop();
    //             }
    //             while(!minQ.empty() && minQ.top().second <= i){
    //                 minQ.pop();
    //             }
    //             i++;                
    //         }

    //         result = max(result, j - i + 1);
    //         j++;
    //     }

    //     return result;
    // }

    // Time : O(n)   Space : O(n) 
    int longestSubarray(vector<int>& nums, int limit) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        deque<int> minQ;
        deque<int> maxQ;

        int result = 0;
        int i = 0;
        int j = 0;

        while(j < n){

            // Modify the max queue
            while(!maxQ.empty() && nums[j] > nums[maxQ.back()]){
                maxQ.pop_back();
            }
            maxQ.push_back(j);

            // Modify the min queue
            while(!minQ.empty() && nums[j] < nums[minQ.back()]){
                minQ.pop_back();
            }
            minQ.push_back(j);

            while(i <= j && nums[maxQ.front()] - nums[minQ.front()] > limit){
                while(!maxQ.empty() && maxQ.front() <= i){
                    maxQ.pop_front();
                }
                while(!minQ.empty() && minQ.front() <= i){
                    minQ.pop_front();
                }
                i++;                
            }

            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};