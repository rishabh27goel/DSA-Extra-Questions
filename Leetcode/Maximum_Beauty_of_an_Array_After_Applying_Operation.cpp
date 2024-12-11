#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int maximumBeauty(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     map<int, int> freqMap;
    //     for(int j = 0; j < n; j++) {
    //         freqMap[nums[j] - k]++;
    //         freqMap[nums[j] + k + 1]--;
    //     }

    //     int maxEqual = 0;
    //     int prefix = 0;

    //     for(auto itr : freqMap) {
    //         prefix += itr.second;
    //         maxEqual = max(maxEqual, prefix);
    //     }

    //     return maxEqual;
    // }

    int maximumBeauty(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        
        int maxNum = *max_element(nums.begin(), nums.end()) + 2 * k + 5;
        int freqMap[maxNum];
        memset(freqMap, 0, 4 * maxNum);

        for(int j = 0; j < n; j++) {
            freqMap[nums[j]]++;
            freqMap[nums[j] + 2 * k + 1]--;
        }

        int maxEqual = 0;
        int prefix = 0;

        for(auto &val : freqMap) {
            prefix += val;
            maxEqual = max(maxEqual, prefix);
        }

        return maxEqual;
    }
};