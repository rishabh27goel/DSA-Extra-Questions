#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int maxWidthRamp(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     vector<int> rightMax(n);
    //     int maxNum = 0;
        
    //     for(int j = n-1; j >= 0; j--) {
    //         maxNum = max(maxNum, nums[j]);
    //         rightMax[j] = maxNum;
    //     }

    //     int result = 0;
    //     int left = 0;
    //     int right = 1;

    //     while(right < n) {
    //         if(nums[left] <= rightMax[right]) {
    //             result = max(result, right - left);
    //             right++;
    //         }
    //         else {
    //             left++;
    //         }
    //     }

    //     return result;
    // }

    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> st;
        for(int j = 0; j < n; j++) {
            if(st.empty() || nums[st.back()] > nums[j]) {
                st.push_back(j);
            }
        }

        int result = 0;
        for(int j = n-1; j >= 0; j--) {
            while(!st.empty() && nums[st.back()] <= nums[j]) {
                result = max(result, j - st.back());
                st.pop_back();
            }
        }

        return result;
    }
};