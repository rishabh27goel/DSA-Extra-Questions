#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        long total = 0;
        for(int j = 0; j < n; j++) 
            total += nums[j];

        // Base Case
        if(total % p == 0)
            return 0;


        int remain = total % p;
        unordered_map<int, int> mp;
        long prefix = 0;

        int result = n + 1;
        for(int j = 0; j < n; j++) {
            prefix = (prefix + nums[j]) % p;

            if(prefix == remain)
                result = min(result, j + 1);

            int find = ((prefix - remain) + p) % p;
            if(mp.find(find) != mp.end())
                result = min(result, j - mp[find]);

            mp[prefix] = j;
        }
        return result >= n ? -1 : result;
    }
};