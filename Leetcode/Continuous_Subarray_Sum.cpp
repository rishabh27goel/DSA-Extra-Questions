#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        unordered_map<int, int> mp;
        int prefix = 0;

        for(int i=0; i<n; i++){
            
            prefix += nums[i];
            int rem = (prefix % k);

            if(rem == 0 && i > 0)
                return true;

            if(mp.find(rem) == mp.end()){
                mp[rem] = i;
            }
            else {
                int idx = mp[rem];
                if(i - idx > 1)
                    return true;
            }
        }

        return false;
    }
};