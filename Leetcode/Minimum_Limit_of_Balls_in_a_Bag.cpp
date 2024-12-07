#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkMinSize(vector<int> &nums, int maxNum, int maxOp) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int op = (int) ceil((double) nums[i] / maxNum);
            maxOp -= (op - 1);

            if(maxOp < 0)   return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int left = 1;
        int right = 1e9;

        int minSize = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(checkMinSize(nums, mid, maxOperations)) {
                minSize = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return minSize;
    }
};