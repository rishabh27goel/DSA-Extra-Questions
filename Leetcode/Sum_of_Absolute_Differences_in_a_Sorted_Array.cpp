#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> left(n, 0);
        int prefix = 0;

        for(int i=0; i<n; i++){

            left[i] = prefix;
            prefix += nums[i];
        }

        vector<int> result;
        int totalSum = prefix;

        for(int i=0; i<n; i++){

            int lS = (nums[i] * i) - left[i];
            int rS = (totalSum - left[i] - nums[i]) - (nums[i] * (n-i-1));
            result.push_back(lS + rS);
        }

        return result;
    }
};