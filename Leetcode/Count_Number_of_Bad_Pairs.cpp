#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // long long countBadPairs(vector<int>& nums) {
    //     int n = nums.size();

    //     long long badPairs = 0;
    //     for(int i = 0; i < n; i++) {
    //         for(int j = i + 1; j < n; j++) {
    //             if(j - i != nums[j] - nums[i]) {
    //                 badPairs++;
    //             }
    //         }
    //     }
    //     return badPairs;
    // }

    // long long countBadPairs(vector<int>& nums) {
    //     long n = nums.size();

    //     unordered_map<long, long> freqMap;
    //     long long goodPairs = 0;

    //     for(int j = 0; j < n; j++) {
    //         long key = 1L * (j - nums[j]);
    //         freqMap[key]++;
    //     }

    //     for(auto itr : freqMap) {
    //         goodPairs += ((itr.second * (itr.second - 1)) / 2);
    //     }

    //     long totalSubarrays = (n * (n - 1)) / 2;
    //     return totalSubarrays - goodPairs;
    // }

    long long countBadPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        long n = nums.size();

        unordered_map<long, int> freqMap;
        long long badPairs = 0;

        for(int j = n-1; j >= 0; j--) {
            long key = 1l * (j - nums[j]);
            long bad = (n - 1) - j;

            badPairs += (bad - freqMap[key]++);
        }       

        return badPairs;
    }
};