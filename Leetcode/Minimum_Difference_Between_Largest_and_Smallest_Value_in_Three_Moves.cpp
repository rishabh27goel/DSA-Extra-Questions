#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        if(n <= 4)  return 0;

        sort(nums.begin(), nums.end());

        int result = INT_MAX;
        int left = 0;
        int right = n-4;

        while(right < n){
            result = min(result, nums[right] - nums[left]);
            left++;
            right++;
        }
            
        return result;
    }
};