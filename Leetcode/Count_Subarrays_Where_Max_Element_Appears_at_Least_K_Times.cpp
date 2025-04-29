#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        // long long countSubarrays(vector<int>& nums, int k) {
        //     ios_base::sync_with_stdio(false);
        //     cin.tie(NULL);
        //     // cout.tie(NULL);
    
        //     long long size = nums.size();
    
        //     int maxNum = 0;
        //     for(int currIdx = 0; currIdx < size; currIdx++)
        //         maxNum = max(maxNum, nums[currIdx]);
        
        //     long long totalSubs = 0;
        //     int maxCount = 0;
    
        //     int leftIdx = 0;
        //     int currIdx = 0;
    
        //     while(currIdx < size) {
        //         maxCount += (maxNum == nums[currIdx]);
        //         while(leftIdx <= currIdx && maxCount >= k) {
        //             maxCount -= (maxNum == nums[leftIdx]);
        //             leftIdx++;
        //         }
        //         totalSubs += (currIdx - leftIdx + 1);
        //         currIdx++;
        //     }
    
        //     return (size * (size + 1)) / 2 - totalSubs;
        // }
    
        long long countSubarrays(vector<int>& nums, int k) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
    
            int size = nums.size();
    
            int maxNum = 0;
            for(int currIdx = 0; currIdx < size; currIdx++)
                maxNum = max(maxNum, nums[currIdx]);
    
    
            long long totalSubs = 0;
            int maxCount = 0;
    
            int leftIdx = 0;
            int currIdx = 0;
    
            while(currIdx < size) {
                maxCount += (maxNum == nums[currIdx]);
                while(leftIdx <= currIdx && maxCount >= k) {
                    maxCount -= (maxNum == nums[leftIdx]);
                    totalSubs += (size - currIdx);
                    leftIdx++;
                }
                currIdx++;
            }
    
            return totalSubs;
        }
    };