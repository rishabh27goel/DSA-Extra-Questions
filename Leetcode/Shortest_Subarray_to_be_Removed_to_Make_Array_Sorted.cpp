#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // The trick about this problem is to realize we can only delete one subarray 
    // 1st inc part + dec part + 2nd inc part
    // We have delete dec part

    int findLengthOfShortestSubarray(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = arr.size();

        int left = 0;
        int right = n-1;

        while(left + 1 < n && arr[left] <= arr[left+1]) {
            left++;
        }

        while(right - 1 >= 0 && arr[right] >= arr[right-1]) {
            right--;
        }

        // No deletions required
        if(left >= right)  return 0;

        int minSub = right;
        int start = 0;
        int end = right;

        while(start <= left) {
            while(end < n && arr[start] > arr[end]) {
                end++;
            }

            minSub = min(minSub, end - start - 1);
            start++;
        }

        return minSub;
    }
};