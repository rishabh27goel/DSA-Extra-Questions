#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        int freqMap[100001] = {0};
        long maxSum = 0;
        long windowSum = 0;

        int unique = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            windowSum += nums[j];
            if(++freqMap[nums[j]] == 1)   unique++;

            if(j - i == k) {
                windowSum -= nums[i];
                if(--freqMap[nums[i]] == 0)   unique--;
                i++;
            }

            if(unique == k)
                maxSum = max(maxSum, windowSum);

            j++;
        }

        return maxSum;
    }
};