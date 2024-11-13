#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int lowerBound(vector<int> &nums, long lower, int start, int end) {
    //     int candidate = -1;
    //     while(start <= end) {
    //         int mid = start + (end - start) / 2;
    //         if((long) nums[mid] >= lower) {
    //             candidate = mid;
    //             end = mid - 1;
    //         }
    //         else {
    //             start = mid + 1;
    //         }
    //     }
    //     return candidate;
    // }

    // int upperBound(vector<int> &nums, int upper, int start, int end) {
    //     int candidate = -1;
    //     while(start <= end) {
    //         int mid = start + (end - start) / 2;
    //         if((long) nums[mid] <= upper) {
    //             candidate = mid;
    //             start = mid + 1;
    //         }
    //         else {
    //             end = mid - 1;
    //         }
    //     }
    //     return candidate;
    // }

    // long long countFairPairs(vector<int>& nums, long lower, long upper) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = nums.size();

    //     // Sort the array
    //     sort(nums.begin(), nums.end());

    //     long long pairs = 0;
    //     for(int j = 0; j < nums.size(); j++) {
    //         int lB = lowerBound(nums, lower - nums[j], j+1, n-1);
    //         int uB = upperBound(nums, upper - nums[j], j+1, n-1);

    //         if(lB != -1 && uB != -1)
    //             pairs += (uB - lB + 1);
    //     }

    //     return pairs;
    // }

    long long lowerSubarrayCount(vector<int> &nums, long value) {
        int n = nums.size();

        long long total = 0;
        int start = 0;
        int end = n-1;

        while(start < end) {
            long currSum = (long) nums[start] + nums[end];
            if(currSum <= value) {
                total += (end - start);
                start++;
            }
            else {
                end--;
            }
        }

        return total;
    }

    long long countFairPairs(vector<int>& nums, long lower, long upper) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        // Sort the array
        sort(nums.begin(), nums.end());
        return lowerSubarrayCount(nums, upper) - lowerSubarrayCount(nums, lower-1);
    }
};
