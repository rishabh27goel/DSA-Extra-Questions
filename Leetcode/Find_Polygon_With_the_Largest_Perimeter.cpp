#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long perimeter = 0; 
        long long prefix = nums[0] + nums[1];
        
        for(int i=2; i<n; i++){

            if(prefix > nums[i]){
                perimeter = max(prefix + nums[i], perimeter);
            }

            prefix += nums[i];
        }

        return perimeter ? perimeter : -1;
    }
};