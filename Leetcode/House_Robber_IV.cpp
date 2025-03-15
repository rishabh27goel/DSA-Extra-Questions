#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
        Here we have n as 1e5 so O(n) and O(n * log(n)) is possible
    */

    // Time : O(2 ^ (size * k))
    // Space : O(size * k)

    // int getMinCapability(int size, vector<int> &nums, int idx, int k) {
    //     if(k == 0)
    //         return 0;

    //     if(idx >= size)
    //         return INT_MAX;

    //     int exclude = getMinCapability(size, nums, idx + 1, k);
    //     int include = max(nums[idx], getMinCapability(size, nums, idx + 2, k - 1));
    
    //     return min(include, exclude);
    // }

    // int minCapability(vector<int>& nums, int k) {
    //     int size = nums.size();

    //     return getMinCapability(size, nums, 0, k);
    // }

    // Time : O(n * log(1e9))
    // Space : O(1)

    // bool isRoberyPossible(int size, vector<int> &nums, int k, int capability) {
    //     int prevIdx = -1;
    //     for(int idx = 0; idx < size; idx++) {
    //         if(nums[idx] <= capability) {
    //             if(prevIdx == -1) {
    //                 k--;
    //                 prevIdx = idx;
    //             }
    //             else {
    //                 if(idx - prevIdx > 1) {
    //                     k--;
    //                     prevIdx = idx;
    //                 }
    //             }
    //         }
    //         if(k <= 0)  return true;
    //     }
    //     return false;
    // }

    // int minCapability(vector<int>& nums, int k) {
    //     int size = nums.size();

    //     int leftCap = 1;
    //     int rightCap = 1e9;

    //     int candidate = 0;
    //     while(leftCap <= rightCap) {
    //         int middleCap = leftCap + (rightCap - leftCap) / 2;
            
    //         if(isRoberyPossible(size, nums, k, middleCap)) {
    //             candidate = middleCap;
    //             rightCap = middleCap - 1;
    //         }
    //         else {
    //             leftCap = middleCap + 1;
    //         }
    //     }
    //     return candidate;
    // }

    int minCapability(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int size = nums.size();

        int leftCap = 1;
        int rightCap = 1e9;

        int candidate = 0;
        while(leftCap <= rightCap) {
            int middleCap = leftCap + (rightCap - leftCap) / 2;

            bool possible = false;
            int prevIdx = -1;
            int count = k;

            for(int idx = 0; idx < size; idx++) {
                if(nums[idx] <= middleCap) {
                    if(prevIdx == -1) {
                        count--;
                        prevIdx = idx;
                    }
                    else {
                        if(idx - prevIdx > 1) {
                            count--;
                            prevIdx = idx;
                        }
                    }
                }
                if(count <= 0) {
                    possible = true;
                    break;
                }
            }
            
            if(possible) {
                candidate = middleCap;
                rightCap = middleCap - 1;
            }
            else {
                leftCap = middleCap + 1;
            }
        }
        return candidate;
    }
};