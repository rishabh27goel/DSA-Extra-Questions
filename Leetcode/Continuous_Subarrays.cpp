#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        long long total = 0;
        map<int, int> freqMap;

        int i = 0;
        int j = 0;

        while(j < n) {
            freqMap[nums[j]]++;

            while(i <= j && freqMap.rbegin()->first - freqMap.begin()->first > 2) {
                freqMap[nums[i]]--;
                if(freqMap[nums[i]] == 0)
                    freqMap.erase(nums[i]);

                i++;
            }

            total += (j - i + 1);
            j++;
        }

        return total;
    }
};