#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        int n = nums.size();

        long long result = 0;
        int minVal = nums[n-1];

        for(int i=n-2; i>=0; i--){

            int parts = ceil((double) nums[i] / (double) minVal);
            result += (parts - 1);

            minVal = (nums[i] / parts);
        }

        return result;
    }
};