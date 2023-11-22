#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    // 42 - 24 == 97 - 79  => 18 == 18

    const int mod = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        unordered_map<long, int> mp;

        for(int i=0; i<n; i++){

            long num = nums[i];
            long rev = 0;

            while(num > 0){

                int dig = num % 10;
                rev *= 10;
                rev += dig;

                num /= 10;
            }

            mp[(long) nums[i] - rev]++;
        }

        long result = 0;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){

            long c = itr->second;

            result = (result + (c * (c-1)) / 2) % mod;
        }

        return result % mod;
    }
};