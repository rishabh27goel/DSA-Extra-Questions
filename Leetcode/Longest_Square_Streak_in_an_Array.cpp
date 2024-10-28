#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int findNumber(vector<int> &nums, long start, long end, long target) {
    //     int n = nums.size();

    //     while(start <= end) {
    //         long mid = start + (end - start) / 2;
    //         if(target == (long) nums[mid] * nums[mid]) 
    //             return mid;
    //         else if(target < (long) nums[mid] * nums[mid]) 
    //             start = mid + 1;
    //         else 
    //             end = mid - 1;
    //     }

    //     return -1;
    // }

    // int longestSquareStreak(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = nums.size();

    //     sort(nums.begin(), nums.end(), greater<int> ());

    //     int maxLength = -1;
    //     vector<int> trackLength(n, 1);

    //     for(int j = 0; j < n; j++) {
    //         int squareIdx = findNumber(nums, j + 1, n - 1, nums[j]);
        
    //         if(squareIdx != -1)
    //             trackLength[squareIdx] = max(trackLength[squareIdx], 1 + trackLength[j]);

    //         if(trackLength[j] >= 2)
    //             maxLength = max(maxLength, trackLength[j]);
    //     }

    //     return maxLength;
    // }

    // int longestSquareStreak(vector<int>& nums) {
    //     int n = nums.size();

    //     bool check[100001];
    //     memset(check, false, sizeof(check));

    //     int maxLen = -1;
    //     for(int j = 0; j < n; j++)
    //         check[nums[j]] = true;

    //     for(int j = 0; j < n; j++) {
    //         if(!check[nums[j]])
    //             continue;

    //         long curr = nums[j];
    //         int length = 0;

    //         while(curr <= 100000 && check[curr]) {
    //             length++;
    //             curr *= curr;
    //         }

    //         if(length >= 2)
    //             maxLen = max(maxLen, length);
    //     }

    //     return maxLen;
    // }

    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();

        bool check[100001];
        memset(check, false, sizeof(check));

        int maxLen = -1;
        for(int j = 0; j < n; j++)
            check[nums[j]] = true;

        for(int j = 1; j <= 100000; j++) {
            if(!check[j])
                continue;

            long curr = j;
            int length = 0;

            while(curr <= 100000 && check[curr]) {
                length++;
                check[curr] = false;
                curr *= curr;
            }

            if(length >= 2)
                maxLen = max(maxLen, length);
        }

        return maxLen;
    }
};