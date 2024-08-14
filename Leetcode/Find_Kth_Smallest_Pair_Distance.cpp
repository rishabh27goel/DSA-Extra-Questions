#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Time : O(n ^ 2 * log(k))   Space : O(k)
    // int smallestDistancePair(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     priority_queue<int> maxHeap;
    //     for(int i = 0; i < n; i++){
    //         for(int j = i + 1; j < n; j++){
    //             maxHeap.push(abs(nums[i] - nums[j]));

    //             if(maxHeap.size() > k){
    //                 maxHeap.pop();
    //             }
    //         }
    //     }

    //     return maxHeap.top();
    // }

    // Observations: 
    // We want to form pairs
    // Which can also be done using sorted array 
    // We know the answer lies between [0, maxNumber]  
    int findPairs(int n, vector<int> &nums, int target) {
        int i = 0;
        int j = 1;

        int pairs = 0;
        while(j < n){
            while(i <= j && nums[j] - nums[i] > target) {
                i++;
            }

            if(j - i > 0){
                pairs += j - i;
            }
            
            j++;
        }

        return pairs;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxNum = *max_element(nums.begin(), nums.end());
        int left = 0;
        int right = maxNum;

        while(left < right){
            int middle = left + (right - left) / 2;
            int pairs = findPairs(n, nums, middle);

            if(pairs >= k) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }
};