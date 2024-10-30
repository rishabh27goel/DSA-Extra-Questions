#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sorted;
    int findPosition(int n, vector<int> &sorted, int target) {
        int idx = -1;
        int start = 0;
        int end = sorted.size() - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(sorted[mid] < target) {
                start = mid + 1;
            }
            else {
                idx = mid;
                end = mid - 1;
            }  
        }

        return idx;
    }

    void findLIS(int n, vector<int> &nums, vector<int> &removal) {
        sorted.clear();

        for(int i = 0; i < n; i++) {
            int idx = findPosition(n, sorted, nums[i]);

            if(idx == -1)
                sorted.push_back(nums[i]);
            else
                sorted[idx] = nums[i];

            removal[i] = sorted.size();
        }
    }

    void findLISReverse(int n, vector<int> &nums, vector<int> &removal) {
        sorted.clear();
        
        for(int i = n-1; i >= 0; i--) {
            int idx = findPosition(n, sorted, nums[i]);

            if(idx == -1)
                sorted.push_back(nums[i]);
            else
                sorted[idx] = nums[i];

            removal[i] = sorted.size();
        }
    }

    int minimumMountainRemovals(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> leftRemove(n);
        findLIS(n, nums, leftRemove);

        vector<int> rightRemove(n);
        findLISReverse(n, nums, rightRemove);

        int minRemoval = INT_MAX;
        for(int i = 1; i < n-1; i++) {
            if(leftRemove[i] > 1 && rightRemove[i] > 1) {
                minRemoval = min(minRemoval, i + 1 - leftRemove[i] + n - i - rightRemove[i]);
            }
        }

        return minRemoval;
    }
};