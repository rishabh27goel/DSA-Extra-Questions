#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> result;

        for(int i=0; i<n; i++){
            int idx = abs(nums[i]) - 1;            
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
            else {
                result.push_back(abs(nums[i]));
            }
        }

        return result;
    }
};