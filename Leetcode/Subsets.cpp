#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> result;
        int p = pow(2, n);

        for(int i=0; i<p; i++){

            vector<int> sub;
            for(int j=0; j<n; j++){
                
                if(i & (1 << j))
                    sub.push_back(nums[j]);
            }

            result.push_back(sub);
        }

        return result;
    }
};