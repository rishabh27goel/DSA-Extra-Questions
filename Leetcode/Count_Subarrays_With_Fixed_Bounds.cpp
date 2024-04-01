#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        long long result = 0;
        int lowerBound = -1; 

        int prevMin = -1;
        int prevMax = -1;

        for(int i=0; i<n; i++){
            if(nums[i] >= minK && nums[i] <= maxK){

                prevMin = (nums[i] == minK) ? i : prevMin;
                prevMax = (nums[i] == maxK) ? i : prevMax;
                result += (min(prevMin, prevMax) - lowerBound);
            }
            else {

                prevMax = i;
                prevMin = i;
                lowerBound = i;
            }
        }

        return result;
    }
};