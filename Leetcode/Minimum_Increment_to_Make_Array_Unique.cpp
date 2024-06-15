#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int minIncrementForUnique(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int total = 0;
        int start = nums[0];

        for(int i=1; i<n; i++) {
            if(start >= nums[i]) {
                start = start + 1;
            }
            else {
                start = nums[i];
            }
            total += abs(nums[i] - start);
        }

        return total;
    }
};