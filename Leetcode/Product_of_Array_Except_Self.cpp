#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> result;

        int product = 1;
        for(int i=0; i<n; i++){

            result.push_back(product);
            product *= nums[i];
        }

        int multiply = 1;
        for(int i=n-1; i>=0; i--){

            result[i] *= multiply;
            multiply *= nums[i];
        }

        return result;
    }
};