#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int result = 0;
        int prefix = 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for(int i=0; i<n; i++){

            prefix += (nums[i] == 0 ? -1 : 1);

            if(mp.find(prefix) != mp.end()){
                result = max(result, i - mp[prefix]);
            }
            else {
                mp[prefix] = i;
            }
        }

        return result;
    }
};