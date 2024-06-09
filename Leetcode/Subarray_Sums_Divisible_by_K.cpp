#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int subarraysDivByK(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> mp(k, 0);
        mp[0] = 1;

        int result = 0;
        int prefix = 0;        

        for(int i=0; i<nums.size(); i++){
            prefix += nums[i];

            int rem = (prefix % k);
            if(rem < 0)  rem += k;

            result += mp[rem];
            mp[rem]++;
        }

        return result;
    }

    // int subarraysDivByK(vector<int>& nums, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     unordered_map<int, int> mp;
    //     mp[0] = 1;

    //     int result = 0;
    //     int prefix = 0;        

    //     for(int i=0; i<nums.size(); i++){
    //         prefix += nums[i];

    //         int rem = (prefix % k);
    //         if(rem < 0)  rem += k;

    //         result += mp[rem];
    //         mp[rem]++;
    //     }

    //     return result;
    // }
};