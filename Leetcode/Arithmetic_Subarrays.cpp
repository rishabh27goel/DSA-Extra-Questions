#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    bool checkSubarray(vector<int> &nums, int s, int e){

        vector<int> vt(nums.begin() + s, nums.begin() + e + 1);
        sort(vt.begin(), vt.end());

        int diff = vt[1] - vt[0];

        for(int i=2; i<vt.size(); i++){

            if(diff != vt[i] - vt[i-1])
                return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = l.size();

        vector<bool> result;

        for(int i=0; i<n; i++){

            result.push_back(checkSubarray(nums, l[i], r[i]));
        }

        return result;
    }
};